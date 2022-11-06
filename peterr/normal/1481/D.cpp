#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
string board[MAXN + 1];

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
        for (int i = 1; i <= n; i++)
        {
            cin >> board[i];
            board[i] = '*' + board[i];
        }
        if (n == 2)
        {
            if (board[1][2] == board[2][1] || (m & 1))
            {
                cout << "YES\n";
                for (int i = 0; i < m + 1; i++)
                {
                    cout << (i & 1) + 1 << " \n"[i == m];
                }
            }
            else
                cout << "NO\n";
            continue;
        }
        int a, b;
        a = b = -1;
        bool found = false;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (i == j)
                    continue;
                if (board[i][j] == board[j][i])
                {
                    found = true;
                    a = i;
                    b = j;
                }
            }
        }
        if (m & 1)
        {
            found = true;
            a = 1;
            b = 2;
        }
        if (found)
        {
            cout << "YES\n";
            for (int i = 0; i < m + 1; i++)
            {
                cout << (i & 1 ? a : b) << " \n"[i == m];
            }
            continue;
        }
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (i == j || j == k || i == k || found)
                        continue;
                    if (board[i][j] != 'a' || board[j][k] != 'a')
                        continue;
                    found = true;
                    cout << "YES\n";
                    int half = (m - 2) / 2;
                    int cur = half & 1 ? j : i;
                    for (int z = 0; z < half + 1; z++)
                    {
                        cout << cur << " ";
                        if (cur == i)
                            cur = j;
                        else
                            cur = i;
                    }
                    cout << j << " " << k << " ";
                    cur = j;
                    for (int z = 0; z < half; z++)
                    {
                        cout << cur << " ";
                        if (cur == j)
                            cur = k;
                        else
                            cur = j;
                    }
                    cout << "\n";
                }
            }
        }
        if (!found)
            cout << "NO\n";
    }
    return 0;
}