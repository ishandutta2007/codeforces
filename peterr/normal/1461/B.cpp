#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
string board[MAXN];
int h[MAXN][MAXN];

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
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || j == m - 1)
                    h[i][j] = board[i][j] == '*';
                else
                {
                    int minH = min(h[i][j - 1], h[i - 1][j]) + 1;
                    int cnt = 0;
                    for (int k = 0; ; k++)
                    {
                        if (j + k >= m || board[i][j + k] == '.')
                            break;
                        cnt++;
                    }
                    h[i][j] = min(cnt, minH);
                }
                //cout << "height " << i << " " << j << " " << h[i][j] << endl;
                ans += h[i][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}