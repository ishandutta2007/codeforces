#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<int> g[MAXN];
int dp[MAXN];
int d[MAXN];

void dfs(int v, int p = -1) {
    int cnt = 0;
    dp[v] = 0;
    for (auto u : g[v]) {
        if (u != p) {
            d[u] = d[v] + 1;
            if (g[u].size() == 1) {
                cnt++;
            }
            dfs(u, v);
            dp[v] += dp[u];
        }
    }
    if (cnt > 0) {
        cnt--;
    }
    dp[v] += (int)g[v].size() - 1 - cnt;
    if (p == -1) {
        dp[v]++;
    }
}

main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() != 1) {
            dfs(i);
            mx = dp[i];
            break;
        }
    }
    set<int> st;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            st.insert(d[i] % 2);
        }
    }
    int mn = st.size();
    if (mn == 2) {
        mn++;
    }
    cout << mn << " " << mx;
    return 0;
}