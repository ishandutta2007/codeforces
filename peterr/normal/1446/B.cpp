#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int ans[MAXN + 1][MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = "#" + s;
    t = "#" + t;
    int realAns = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                ans[i][j] = 2 + ans[i - 1][j - 1];
            }
            else
            {
                ans[i][j] = max(ans[i][j], ans[i - 1][j] - 1);
                ans[i][j] = max(ans[i][j], ans[i][j - 1] - 1);
            }
            realAns = max(realAns, ans[i][j]);
        }
    }
    cout << realAns << "\n";
    return 0;
}