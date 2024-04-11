#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n * 51);
    auto addedge = [&](int u, int v, int w) {
        G[u * 51].push_back({v * 51 + w, 0});
        for (int was = 1; was <= 50; ++was) {
            G[u * 51 + was].push_back({v * 51, (was + w) * (was + w) });
        }
    };
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    set<pair<int, int>> st;
    int inf = 1e9 + 7;
    vector<int> d(G.size(), inf);
    d[0] = 0;
    st.insert({d[0], 0});
    while (st.size()) {
        auto f = *st.begin();
        st.erase(st.begin());
        for (auto i : G[f.second]) {
            if (d[i.first] > d[f.second] + i.second) {
                st.erase({d[i.first], i.first});
                d[i.first] = d[f.second] + i.second;
                st.insert({d[i.first], i.first});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int ans = d[i * 51];
        if (ans == inf) cout << "-1 ";
        else cout << ans << ' ';
    }
    return 0;
}