#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
#include <list>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()
#define itl list<block>::iterator

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md1 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


struct segment_tree {
    struct Node {
        int mx1 = 0, mx0 = 0;
        int upd = 0;

        void combine(const Node &a, const Node &b) {
            mx1 = max(a.mx1, b.mx1);
            mx0 = max(a.mx0, b.mx0);
            if (upd) swap(mx1, mx0);
        }

        void init(pair<int, int> x) {
            mx0 = mx1 = 0;
            if (x.second == 1) mx1 = x.first;
            else mx0 = x.first;
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k, vector<pair<int, int>> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<pair<int, int>> &a) {
        if (l + 1 == r) {
            tree[v].init(a[l]);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make((v << 1) + 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    void upd(int v, int l, int r, int &lq, int &rq) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            swap(tree[v].mx0, tree[v].mx1);
            tree[v].upd ^= 1;
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    void upd(int lq, int rq) {
        upd(1, 0, n, lq, rq);
    }

    int get() {
        return tree[1].mx0;
    }
};

int n;
vector<pair<int, int>> g[maxN];
pair<int, int> edges[maxN];

struct solver {
    segment_tree st;
    vector<int> l, r;
    vector<pair<int, int>> a;
    int root;

    void build(int &ro) {
        root = ro;
        l.resize(n + 1);
        r.resize(n + 1);
        a.emplace_back(0, 0);
        dfs(root, -1);
        st.build(n, a);
    }

    void dfs(int v, int p) {
        l[v] = (int) a.size() - 1;
        for (auto &[u, t]: g[v]) {
            if (u == p) continue;
            a.emplace_back(a[l[v]].first + 1, a[l[v]].second ^ t);
            dfs(u, v);
        }
        r[v] = a.size();
    }

    int get_max() {
        return st.get();
    }

    void upd(int u, int v) {
        if (l[v] < l[u]) swap(u, v);
        st.upd(l[v], r[v]);
    }
};

int d = -1;
int a = -1, b = -1;

pair<int, int> find_diametr(int v, int p) {
    pair<int, int> mx1 = {0, v}, mx2 = {-1, -1};
    for (auto &[u, t]: g[v]) {
        if (u == p) continue;
        auto kek = find_diametr(u, v);
        if (kek > mx1) {
            mx2 = mx1;
            mx1 = kek;
        } else if (kek > mx2) {
            mx2 = kek;
        }
    }
    if (d < mx1.first + mx2.first) {
        d = mx1.first + mx2.first;
        a = mx1.second;
        b = mx2.second;
    }
    mx1.first += 1;
    return mx1;
}

void solve() {
    cin >> n;
    range(i, n - 1) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
        edges[i] = {u, v};
    }
    find_diametr(1, -1);
    solver sl1, sl2;
    sl1.build(a);
    sl2.build(b);
    int m;
    cin >> m;
    range(i, m) {
        int id;
        cin >> id;
        id--;
        sl1.upd(edges[id].first, edges[id].second);
        sl2.upd(edges[id].first, edges[id].second);
        cout << max(sl1.get_max(), sl2.get_max()) << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}