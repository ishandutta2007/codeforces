#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int K = 2010;
const int INF = 1e9;

int n, m, k;
int best[N];
int a[N];
int sum[K];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> v >> u;
        best[v] = max(best[v], u);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
        for (int j = 0; j < i; j++) {
            int cost = sum[i] - sum[j + best[i - j]];
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }
    cout << dp[k] << endl;
    return 0;
}