#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

template <typename T1, typename T2, typename T3>
struct triple {
    T1 first;
    T2 second;
    T3 third;
    triple(): first(), second(), third() {}
    triple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) {}

    bool operator==(const triple& rhs) const { return tie(first, second, third) == tie(rhs.first, rhs.second, rhs.third); }
    bool operator!=(const triple& rhs) const { return !(*this == rhs); }
    bool operator< (const triple& rhs) const { return tie(first, second, third) < tie(rhs.first, rhs.second, rhs.third); }
    bool operator> (const triple& rhs) const { return rhs < *this; }
    bool operator<=(const triple& rhs) const { return !(*this > rhs); }
    bool operator>=(const triple& rhs) const { return !(*this < rhs); }
};

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

int n, m, p[N], high[N], tin[N], tout[N], T;
vector<int> g[N];
vector<triple<int, int, ll>> edges(1);

void dfs(int x, int par) {
    p[x] = par;
    tin[x] = T++;

    for (int &i : g[x]) {
        if (i == par) continue;
        if (edges[i].first != x)
            dfs(edges[i].first, i);
        else dfs(edges[i].second, i);
    }
    tout[x] = T++;
}

bool f(int u, int v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

UnionFind uf;
void merge(int u, int v) {
    int keep = 0;
    if (f(high[uf.find(u)], high[uf.find(v)]))
        keep = high[uf.find(u)];
    else keep = high[uf.find(v)];
    uf.merge(u, v);
    high[uf.find(u)] = keep;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        ll x;
        cin >> u >> v >> x;
        g[u].emplace_back(i);
        g[v].emplace_back(i);
        edges.emplace_back(u, v, x);
    }

    dfs(1, 0);

    uf = UnionFind(n);
    iota(high, high + n + 1, 0);

    for (int i = 1; i < n; i++) {
        auto [u, v, w] = edges[i];
        if (w == 1) {
            merge(u, v);
        }
    }

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b; ll y;
            cin >> a >> b >> y;

            int cur = high[uf.find(a)];
            while (!f(cur, b) and y) {
                auto [u, v, w] = edges[p[cur]];
                y /= w;
                if (u != cur)
                    cur = high[uf.find(u)];
                else cur = high[uf.find(v)];
            }

            cur = high[uf.find(b)];
            while (!f(cur, a) and y) {
                auto [u, v, w] = edges[p[cur]];
                y /= w;
                if (u != cur)
                    cur = high[uf.find(u)];
                else cur = high[uf.find(v)];
            }

            cout << y << "\n";
        }
        else {
            int i; ll c;
            cin >> i >> c;
            edges[i].third = c;
            if (c == 1) {
                merge(edges[i].first, edges[i].second);
            }
        }
    }
    return 0;
}