#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int s[MAXN];
long long dp[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++)
    {
        int mx = s[i];
        int mn = s[i];
        for (int j = i - 1; j >= 0; j--)
        {
            mx = max(mx, s[j]);
            mn = min(mn, s[j]);
            dp[j][i] = mx - mn + min(dp[j + 1][i], dp[j][i - 1]);
            //cout << "dp " << j << " "<< i << " " << dp[j][i] << endl;
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}