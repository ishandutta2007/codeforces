#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
string board[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
        }
        if (n <= 2)
        {
            for (int i = 0; i < m; i++)
                board[0][i] = 'X';
        }
        else if (m <= 2)
        {
            for (int i = 0; i < n; i++)
                board[i][0] = 'X';
        }
        else
        {
            for (int i = 0; i < m; i += 3)
            {
                for (int j = 0; j < n; j++)
                    board[j][i] = 'X';
                if (i > 0)
                {
                    bool found = false;
                    for (int j = 0; j < n; j++)
                    {
                        if (board[j][i - 1] == 'X' || board[j][i - 2] == 'X')
                        {
                            found = true;
                            board[j][i - 1] = board[j][i - 2] = 'X';
                            break;
                        }
                    }
                    if (!found)
                        board[0][i - 1] = board[0][i - 2] = 'X';
                }
            }
            if (m % 3 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (board[i][m - 1] == 'X')
                        board[i][m - 2] = 'X';
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << board[i] << "\n";
    }
    return 0;
}