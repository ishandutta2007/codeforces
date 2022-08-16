#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

class UnionFind {
public:
    int n;
    vector<int> p, r;

    UnionFind(): n(), p(), r() {}
    UnionFind(int n): n(n), p(n + 1), r(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int size() const {
        return n;
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        int l1 = find(x);
        int l2 = find(y);

        if (l1 == l2)
            return false;
        if (r[l1] > r[l2])
            p[l2] = l1;
        else if (r[l1] < r[l2])
            p[l1] = l2;
        else {
            p[l2] = l1;
            r[l1]++;
        }
        n--;
        return true;
    }
};

struct point {
    int x, y;
    point(): x(), y() {}
    point(int x, int y): x(x), y(y) {}
};

const int N = 2000 + 5;

int n, c[N], k[N], cur[N];
point a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(cur, cur + N, 0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> k[i];

    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll cost = (k[i] + k[j]) * (ll)((abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)));
            edges.emplace_back(cost, make_pair(i, j));
        }
    }

    sort(edges.begin(), edges.end());
    ll ans = accumulate(c + 1, c + n + 1, 0ll);

    vector<pair<int, int>> ans_edges;
    UnionFind uf(n);

    for (int i = 0; i < edges.size(); i++) {
        ll w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;

        int u1 = uf.find(u);
        int v1 = uf.find(v);

        if (w < max(c[cur[u1]], c[cur[v1]]) and uf.merge(u1, v1)) {
            ans -= max(c[cur[u1]], c[cur[v1]]);
            ans += w;
            cur[uf.find(u1)] = c[cur[u1]] > c[cur[v1]] ? cur[v1] : cur[u1];
            ans_edges.emplace_back(u, v);
        }
    }

    set<int> ans_stations;
    for (int i = 1; i <= n; i++) ans_stations.insert(cur[uf.find(i)]);

    cout << ans << "\n" << ans_stations.size() << "\n";
    for (int i : ans_stations) cout << i << " "; cout << "\n";

    cout << ans_edges.size() << "\n";
    for (auto &[x, y] : ans_edges) cout << x << " " << y << "\n";
    return 0;
}