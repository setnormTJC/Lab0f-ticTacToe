#include <iostream>
#include <vector>

using namespace std;


void printGrid(vector<vector<char>> theGrid) //"terse"
{
    cout << "============" << endl;
    for (auto& row : theGrid)
    {
        cout << "|";
        for (auto& element : row)
        {
            cout << element << " | ";
        }
        cout << "\n"; //separates rows from one another
    }
    cout << "============" << endl;
}

bool checkForMainDiagonalWin(const vector<vector<char>>& ticTacToeGrid)
{

    //char charAt00 = ticTacToeGrid.at(0).at(0); 
    char charAt00 = ticTacToeGrid[0][0];
    char charAt11 = ticTacToeGrid[1][1];
    char charAt22 = ticTacToeGrid[2][2];

    if ((charAt00 == charAt11) && (charAt11 == charAt22))
    {
        return true; 
    }

    else
    {
        return false; 
    }
}

bool checkForRowWin(const vector<vector<char>>& ticTacToeGrid)
{
    for (int row = 0; row < 3; row++)
    {
        char charAtCol0 = ticTacToeGrid[row][0]; 
        char charAtCol1 = ticTacToeGrid[row][1];
        char charAtCol2 = ticTacToeGrid[row][2];

        if (charAtCol0 == charAtCol1 && charAtCol1 == charAtCol2)
        {
            return true;
        }

    } //end for loop

    return false; 
}

/// <summary>
/// P
/// </summary>
/// <param name="ticTacToeGrid"></param>
/// <param name="playerID">Player ID is either "P1" or "P2"</param>
void updateGrid(vector<vector<char>>& ticTacToeGrid, const string& playerID) 
{
    int desiredRow, desiredColumn; 

    if (playerID == "P1")
    {
        cout << "P1 - enter the row and column at which you want to put an 'x'" << endl; 
        cin >> desiredRow >> desiredColumn;
        cout << "Placing aN 'x' at row " << desiredRow << " and column: " << desiredColumn << endl;

        ticTacToeGrid[desiredRow][desiredColumn] = 'x';
    }

    else
    {
        cout << "PTWO! - enter the row and column at which you want to put an 'o'" << endl;
        cin >> desiredRow >> desiredColumn;
        cout << "Placing aN 'o' at row " << desiredRow << " and column: " << desiredColumn << endl;

        ticTacToeGrid[desiredRow][desiredColumn] = 'o';

    }
}

bool checkForWinPeriod(vector<vector<char>>& ticTacToeGrid)//function-happy!
{
    checkForMainDiagonalWin(ticTacToeGrid); 
    //checkForSecondaryDiagonalWin(ticTacToeGrid);
    //checkForRowWin(ticTacToeGrid); 
    //checkForColumnWin(ticTacToeGrid);

    return false; 
}

int main()
{
    //auto a = 5.0f; 
    vector<vector<char>> ticTacToeGrid =
    {
        {'o', 'o', ' '},
        {' ', ' ', ' '},
        {'x', 'x', ' '}
    };

    //ticTacToeGrid[playerInputX][playerInputY] = 'x' //what the `updateGrid` fn might look like

    cout << "Initial state of the gameboard: " << endl; 
    printGrid(ticTacToeGrid);


    bool gameWon = false; //game WON

    while (!gameWon)
    {
        //prompt P1 and P2 for inputs (ie : call `updateGrid`)

        string player1 = "P1";
        string player2 = "P2";

        updateGrid(ticTacToeGrid, player1); //pass by reference 

        //gameWon = checkForWinPeriod(ticTacToeGrid);
        cout << "Checking for ROW win..." << endl; 
        gameWon = checkForRowWin(ticTacToeGrid);

        if (gameWon)
        {
            break; //spaghetti code
        }

        cout << std::boolalpha; //this displays "true" instead of 1 and "false" instead of 0
        cout << gameWon << endl;

        system("pause");
        system("CLS");


        updateGrid(ticTacToeGrid, player2);
        printGrid(ticTacToeGrid);

        gameWon = checkForRowWin(ticTacToeGrid);

        cout << std::boolalpha; //this displays "true" instead of 1 and "false" instead of 0
        cout << gameWon << endl;


        if (gameWon)
        {
            break;
        }


    }

    return 0;
}