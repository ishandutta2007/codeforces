#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int dp[MAXN];

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
            cin >> a[i];
        }
        int ans = a[0];
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = a[i] + (i + a[i] < n ? dp[i + a[i]] : 0);
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}