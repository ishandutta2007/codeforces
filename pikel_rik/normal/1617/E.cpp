#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> values = {0};
    for (auto x : a) {
        for (; x > 0;) {
            values.push_back(x);
            int lg = 32 - __builtin_clz(x) - ((x & (x - 1)) == 0);
            x = (1 << lg) - x;
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    int sz = (int) values.size();

    auto id = [&](int x) -> int {
        return lower_bound(values.begin(), values.end(), x) - values.begin();
    };

    vector<vector<int>> g(sz);
    for (auto x : a) {
        int id_x = id(x);
        for (; x > 0;) {
            int lg = 32 - __builtin_clz(x) - ((x & (x - 1)) == 0);
            int nxt_x = (1 << lg) - x, nxt_id = id(nxt_x);
            g[id_x].push_back(nxt_id);
            g[nxt_id].push_back(id_x);
            x = nxt_x, id_x = nxt_id;
        }
    }

    vector<int> dist(sz);
    auto bfs = [&](int s) -> pair<int, int> {
        fill(dist.begin(), dist.end(), -1);

        queue<int> q;
        q.push(s);
        dist[s] = 0;

        int furthest = s;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                    if (dist[v] > dist[furthest]) {
                        furthest = v;
                    }
                }
            }
        }

        return make_pair(furthest, dist[furthest]);
    };

    int u = bfs(0).first;
    auto [v, m] = bfs(u);

    int x = find(a.begin(), a.end(), values[u]) - a.begin();
    int y = find(a.begin(), a.end(), values[v]) - a.begin();

    cout << x + 1 << ' ' << y + 1 << ' ' << m << '\n';
    return 0;
}