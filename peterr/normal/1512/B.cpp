#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
string board[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> board[i];
        int r1 = -1;
        int c1 = -1;
        int r2 = -1;
        int c2 = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '*')
                    continue;
                if (r1 == -1)
                {
                    r1 = i;
                    c1 = j;
                }
                else
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }
        if (r1 == r2)
        {
            if (r1 == 0)
                board[1][c1] = board[1][c2] = '*';
            else
                board[0][c1] = board[0][c2] = '*';
        }
        else if (c1 == c2)
        {
            if (c1 == 0)
                board[r1][1] = board[r2][1] = '*';
            else
                board[r1][0] = board[r2][0] = '*';
        }
        else
        {
            board[r1][c2] = board[r2][c1] = '*';
        }
        for (int i = 0; i< n; i++)
            cout << board[i] << "\n";
    }
    return 0;
}