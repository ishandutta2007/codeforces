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
const int N = 2e5 + 5;

int n, a[N], d[N], st[N], fi[N], T = 1;
vector<int> g[N];

template <typename T, typename F = function<T(const T&, const T&)>> class FenwickTree {
public:
    int n;
    vector<T> bit;
    F f;
    explicit FenwickTree(int _n, F func) : n(_n), f(move(func)) {
        bit.resize(n + 1);
    }
    void add(int i, int val) {
        while (i < n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

void dfs(int x, int p, int dep) {
    d[x] = dep;
    st[x] = T++;

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x, dep + 1);
    }

    fi[x] = T++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);
    FenwickTree<ll> f0(T + 1, plus<>()), f1(T + 1, plus<>());

    while (m--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            int v; cin >> v;
            if (d[x] % 2 == 0) {
                f0.add(st[x], v);
                f0.add(fi[x] + 1, -v);
                f1.add(st[x], -v);
                f1.add(fi[x] + 1, v);
            }
            else {
                f1.add(st[x], v);
                f1.add(fi[x] + 1, -v);
                f0.add(st[x], -v);
                f0.add(fi[x] + 1, v);
            }
        }
        else {
            if (d[x] % 2 == 0)
                cout << a[x] + f0.sum(st[x]) << "\n";
            else cout << a[x] + f1.sum(st[x]) << "\n";
        }
    }
    return 0;
}