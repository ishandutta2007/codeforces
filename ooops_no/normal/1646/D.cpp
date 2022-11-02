#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N], ans(N);
vector<vector<pair<int,int>>> dp(N, vector<pair<int,int>>(2));

void dfs(int v, int p) {
    dp[v][1] = {1, g[v].size()};
    dp[v][0] = {0, 1};
    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v);
            if (dp[to][0].first > dp[to][1].first || (dp[to][0].first == dp[to][1].first && dp[to][0].second < dp[to][1].second)) {
                dp[v][0].first += dp[to][0].first;
                dp[v][0].second += dp[to][0].second;
            } else {
                dp[v][0].first += dp[to][1].first;
                dp[v][0].second += dp[to][1].second;
            }
            dp[v][1].first += dp[to][0].first;
            dp[v][1].second += dp[to][0].second;
        }
    }
}

void zhfs(int v, int p, int d) {
    if (d == 1) {
        ans[v] = g[v].size();
    } else {
        ans[v] = 1;
    }
    for (auto to : g[v]) {
        if (to != p) {
            if (d == 0) {
                if (dp[to][0].first > dp[to][1].first || (dp[to][0].first == dp[to][1].first && dp[to][0].second < dp[to][1].second)) {
                    zhfs(to, v, 0);
                } else {
                    zhfs(to, v, 1);
                }
            } else {
                zhfs(to, v, 0);
            }
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    if (n == 2) {
        cout << 2 << ' ' << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    dfs(0, -1);
    if (dp[0][0].first > dp[0][1].first || (dp[0][0].first == dp[0][1].first && dp[0][0].second < dp[0][1].second)) {
        zhfs(0, -1, 0);
    } else {
        zhfs(0, -1, 1);
    }
    cout << max(dp[0][0].first, dp[0][1].first) << " " << accumulate(ans.begin(), ans.end(), 0ll) << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}