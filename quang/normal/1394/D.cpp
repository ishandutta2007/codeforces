#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = 1ll << 60;

int n;
int t[N], h[N];
vector<int> adj[N];
long long dp[N][2];

void dfs(int u, int p) {
    int cnt[2] = {0, 0};
    long long tot = 0;
    vector<long long> ls;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (h[u] > h[v]) {  
            cnt[0]++;
            tot += dp[v][0];
        } else if (h[u] < h[v]) {
            cnt[1]++;
            tot += dp[v][1];
        } else {
            ls.push_back(dp[v][0] - dp[v][1]);
            tot += dp[v][1];
        }
    }
    sort(ls.begin(), ls.end());
    dp[u][0] = dp[u][1] = INF;
    for (int i = 0; i <= ls.size(); i++) {
        if (i > 0) tot += ls[i - 1];
        int maxVal = max(cnt[0] + i, cnt[1] + (int)ls.size() - i);
        if (p == 0) {
            dp[u][0] = min(dp[u][0], tot + 1ll * maxVal * t[u]);
        } else {
            if (h[p] > h[u]) {
                dp[u][0] = min(dp[u][0], tot + 1ll * t[u] * max(cnt[0] + i, cnt[1] + (int)ls.size() - i + 1));
            } else if (h[p] < h[u]) {
                dp[u][1] = min(dp[u][1], tot + 1ll * t[u] * max(cnt[0] + i + 1, cnt[1] + (int)ls.size() - i));
            } else {
                dp[u][0] = min(dp[u][0], tot + 1ll * t[u] * max(cnt[0] + i, cnt[1] + (int)ls.size() - i + 1));
                dp[u][1] = min(dp[u][1], tot + 1ll * t[u] * max(cnt[0] + i + 1, cnt[1] + (int)ls.size() - i));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][0] << endl;
    return 0;
}