#include <bits/stdc++.h>

using namespace std;

int board[9][9];
int ind[9][2] = {{0, 0}, {1, 3}, {2, 6}, {3, 1}, {4, 4}, {5, 7}, {6, 2}, {7, 5}, {8, 8}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n = 9;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
                board[i][j] = s[j] - '0';
        }
        for (int i = 0; i < 9; i++)
        {
            int x = ind[i][0];
            int y = ind[i][1];
            board[x][y] = (board[x][y] - 1 + 1) % 9 + 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j];
            cout << "\n";
        }
    }

    return 0;
}