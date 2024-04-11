#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T, typename F = function<T(const T&, const T&)>> class FenwickTree {
public:
    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}

    void init(int _n, F func = plus<T>()) {
        f = move(func);
        n = _n;
        bit.resize(n + 1);
    }

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        int ans = 0;
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

int n, dist[N], id[N], cur;
vector<int> g[N], branch[N];

void dfs(int x, int p = 0) {
    id[x] = cur;
    branch[cur].push_back(x);

    dist[x] = 1 + dist[p];

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    FenwickTree<int> ft[g[1].size()], ftd;

    dist[1] = 1;
    for (int &i : g[1]) {
        branch[cur].push_back(1);
        dfs(i, 1);
        ft[cur].init(branch[cur].size() + 1);
        cur++;
    }

    ftd.init(*max_element(dist + 1, dist + n + 1));

    while (q--) {
        int t;
        cin >> t;

        if (t == 0) {
            int v, x, d;
            cin >> v >> x >> d;

            if (dist[v] <= d + 1) {
                ftd.add(1, x);
                ftd.add(d - dist[v] + 3, -x);
                ft[id[v]].add(d - dist[v] + 3, x);
                ft[id[v]].add(min(dist[v] + d + 1, (int)branch[id[v]].size() + 1), -x);
            }
            else {
                ft[id[v]].add(max(1, dist[v] - d), x);
                ft[id[v]].add(min(dist[v] + d + 1, (int)branch[id[v]].size() + 1), -x);
            }
        }
        else {
            int v;
            cin >> v;

            cout << ftd.query(dist[v]) + ft[id[v]].query(dist[v]) << "\n";
        }
    }
    return 0;
}