#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 3E5;
const int MAXM = 10;
long long dp[MAXN][MAXM + 1];
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0][1] = (ll) arr[0] - k;
    ll ans = max((ll) 0, dp[0][1]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= min(m, i + 1); j++)
        {
            if (j != 1)
            {
                dp[i][j] = arr[i] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max((ll) arr[i] - k, arr[i] + dp[i - 1][m] - k);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}