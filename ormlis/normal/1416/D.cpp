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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int dsu[maxN];
vector<int> g[maxN];
int tin[maxN], tout[maxN];
int nu;

int get_dsu(int a) {
    if (dsu[a] == a) return a;
    return dsu[a] = get_dsu(dsu[a]);
}

void unio(int a, int b) {
    a = get_dsu(a), b = get_dsu(b);
    if (a == b) return;
    dsu[a] = nu;
    dsu[b] = nu;
    g[nu].push_back(a);
    g[nu].push_back(b);
    nu++;
}


struct segment_tree {
    struct Node {
        int val = 0;
        int ind = 0;
    };
    vector<Node> tree{};
    int n{};

    void build(int k, vector<int> &a) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n, a);
    }

    Node su(const Node &a, const Node &b) {
        if (a.val > b.val) return a;
        return b;
    }

    void make(int v, int l, int r, vector<int> &a) {
        if (l + 1 == r) {
            tree[v] = {a[l], l};
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make((v << 1) + 1, (l + r) >> 1, r, a);
        tree[v] = su(tree[v << 1], tree[(v << 1) + 1]);
    }

    void upd(int v, int l, int r, int pos, int x) {
        if (l + 1 == r) {
            tree[v].val = x;
            return;
        }
        int mid = (r + l) >> 1;
        if (pos < mid) {
            upd(v << 1, l, mid, pos, x);
        } else {
            upd((v << 1) + 1, mid, r, pos, x);
        }
        tree[v] = su(tree[v << 1], tree[(v << 1) + 1]);
    }

    Node get(int v, int l, int r, int lq, int rq) {
        if (r <= lq || l >= rq) return {0, 0};
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        auto a = get(v << 1, l, (l + r) >> 1, lq, rq);
        auto b = get((v << 1) + 1, (l + r) >> 1, r, lq, rq);
        return su(a, b);
    }

    void upd(int pos, int x) {
        upd(1, 0, n, pos, x);
    }

    Node get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n + 1);
    range(i, maxN) dsu[i] = i;
    range(i, n) cin >> p[i + 1];
    vector<pair<int, int>> edges(m);
    vector<int> ue(m, 0);
    range(i, m) cin >> edges[i].first >> edges[i].second;
    vector<pair<int, int>> quer(q);
    nu = n + 2;
    range(i, q) {
        cin >> quer[i].first >> quer[i].second;
        if (quer[i].first == 2) {
            quer[i].second--;
            ue[quer[i].second] = 1;
        }
    }
    range(i, m) if (!ue[i]) unio(edges[i].first, edges[i].second);
    vector<int> where_answer;
    reverse(all(quer));
    for (auto &[t, v] : quer) {
        if (t == 1) {
            where_answer.push_back(get_dsu(v));
            continue;
        } else {
            unio(edges[v].first, edges[v].second);
        }
    }
    int time = 0;
    function<void(int)> dfs = [&](int v) {
        tin[v] = time;
        time++;
        for (auto &u: g[v]) {
            dfs(u);
        }
        tout[v] = time;
    };
    for (int i = 1; i < nu; ++i) {
        if (get_dsu(i) == i) {
            dfs(i);
        }
    }
    vector<int> arr(time);
    for (int i = 1; i <= n; ++i) arr[tin[i]] = p[i];
    segment_tree st;
    st.build(time, arr);
    reverse(all(where_answer));
    for (auto &v: where_answer) {
        auto w = st.get(tin[v], tout[v]);
        cout << w.val << "\n";
        if (w.val != 0) st.upd(w.ind, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}