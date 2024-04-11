#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
ll N, ans, dp[100005][23][3];
vi A;
vvi G;
void dfs(ll n, ll p) {
    for (int i = 0; i < 20; i++) {
        dp[n][i][((A[n] & (1ll << i))? 1 : 0)] = 1;
        dp[n][i][((A[n] & (1ll << i))? 0 : 1)] = 0;
    }
    for (auto i : G[n]) {
        if (i == p) continue;
        dfs(i, n);
        for (int j = 0; j < 20; j++) {
            ans += ((1ll << j) * ((dp[n][j][0] * dp[i][j][1]) + (dp[n][j][1] * dp[i][j][0])));
            if ((A[n] & (1ll << j))) swap(dp[i][j][0], dp[i][j][1]);
            dp[n][j][0] += dp[i][j][0];
            dp[n][j][1] += dp[i][j][1];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    A.resize(N + 5); G.resize(N + 5);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        ans += A[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << "\n";
}