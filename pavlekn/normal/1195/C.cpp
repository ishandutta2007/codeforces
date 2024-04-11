#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int dp[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i + 1][0] = max(a[i] + dp[i][1], dp[i][0]);
        dp[i + 1][1] = max(b[i] + dp[i][0], dp[i][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;;
}