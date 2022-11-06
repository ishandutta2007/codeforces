#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int ans[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (a * n != b * m)
            cout << "NO\n";
        else
        {
            int curCol = 0;
            for (int i = 0; i < n; i++)
            {
                fill(ans[i], ans[i] + m, 0);
                for (int j = 0; j < a; j++)
                {
                    ans[i][curCol] = 1;
                    curCol++;
                    if (curCol >= m)
                        curCol = 0;
                }
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << ans[i][j];
                cout << "\n";
            }
        }
    }
    return 0;
}