#include <bits/stdc++.h>

using namespace std;
int n, k, ans, dp[5005][505], h[11];
int solve(int a, int b) {
    if (a==0 || b==0 || dp[a][b]) {
        return dp[a][b];
    }
    for (int i=1; i<=min(a, k); i++) {
        dp[a][b]=max(dp[a][b], solve(a-i, b-1)+h[i]);
    }
    return dp[a][b];
}
map<int, int> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n*k; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i=1; i<=k; i++) {
        cin >> h[i];
    }
    for (auto p:b) {
        ans+=solve(a[p.first], p.second);
    }
    cout << ans << "\n";
    return 0;
}