//Complete Tic-Tac-Toe C++ code

#include <iostream>
using namespace std;

// Create the game board
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Store whose turn it is
char turn = 'X';

// Display the board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | "
         << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | "
         << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | "
         << board[2][1] << " | " << board[2][2] << "\n\n";
}

// Check whether someone has won
bool checkWin() {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == turn &&
            board[i][1] == turn &&
            board[i][2] == turn) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == turn &&
            board[1][i] == turn &&
            board[2][i] == turn) {
            return true;
        }
    }

    // Check first diagonal
    if (board[0][0] == turn &&
        board[1][1] == turn &&
        board[2][2] == turn) {
        return true;
    }

    // Check second diagonal
    if (board[0][2] == turn &&
        board[1][1] == turn &&
        board[2][0] == turn) {
        return true;
    }

    return false;
}

// Check whether the board is full
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

// Allow a player to make a move

// Allow a player to make a valid move
bool playerTurn() {
    int choice;
    int row, column;

    cout << "Player " << turn
         << ", choose a square (1-9): ";

    if (!(cin >> choice)) {
        cout << "Please enter a number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }

    if (choice < 1 || choice > 9) {
        cout << "Invalid choice! Try again.\n";
        return false;
    }

    row = (choice - 1) / 3;
    column = (choice - 1) % 3;

    if (board[row][column] == 'X' ||
        board[row][column] == 'O') {
        cout << "Square occupied! Try again.\n";
        return false;
    }

    board[row][column] = turn;
    return true;
}

// Use this main function instead
int main() {
    cout << "===== TIC-TAC-TOE GAME =====\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    while (true) {
        displayBoard();

        if (!playerTurn()) {
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << turn << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        turn = (turn == 'X') ? 'O' : 'X';
    }

    cout << "Game over. Thanks for playing!\n";
    return 0;
}
