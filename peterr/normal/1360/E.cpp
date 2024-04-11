#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
string board[MAXN];

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
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '0')
                    continue;
                if (i == n - 1 || j == n - 1)
                    continue;
                if (board[i + 1][j] == '0' && board[i][j + 1] == '0')
                    ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}