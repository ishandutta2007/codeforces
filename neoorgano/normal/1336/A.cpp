#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
vector<int> g[MAXN];
int d[MAXN], sz[MAXN], p[MAXN], cnt[MAXN];

void dfs(int v) {
    sz[v] = 0;
    cnt[v] = 0;
    for (auto u : g[v]) {
        if (u != p[v]) {
            cnt[v]++;
            d[u] = d[v] + 1;
            p[u] = v;
            dfs(u);
            sz[v] += sz[u] + 1;
        }
    }
}

main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    p[0] = -1;
    d[0] = 0;
    dfs(0);
    set<array<int, 2>> st;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0) {
            st.insert({d[i] - sz[i], i});
        }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        auto it = st.end();
        it--;
        auto el = *it;
        st.erase(it);
        ans += el[0];
        int v = el[1];
        cnt[p[v]]--;
        if (cnt[p[v]] == 0) {
            st.insert({d[p[v]] - sz[p[v]], p[v]});
        }
    }
    cout << ans;
    return 0;
}