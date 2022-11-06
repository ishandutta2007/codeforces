#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
string board[MAXN];

int cnt(int n, int x, int o)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num = (i + j) % 3;
            if (board[i][j] == '.')
                continue;
            if (board[i][j] == 'X' && num == x)
                ans++;
            if (board[i][j] == 'O' && num == o)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
            for (int j = 0; j < n; j++)
                if (board[i][j] != '.')
                    total++;
        }
        int x, o;
        x = o = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;
                if (cnt(n, i, j) <= total / 3)
                {
                    x = i;
                    o = j;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = (i + j) % 3;
                if (board[i][j] == 'X' && num == x)
                    board[i][j] = 'O';
                else if (board[i][j] == 'O' && num == o)
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++)
            cout << board[i] << "\n";
    }
    return 0;
}