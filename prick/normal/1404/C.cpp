//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

const int inf = (int) 1e9;
const int tsize = 1 << 19;

struct Node {
    int can_count;
    int add;
    int minval;
};

Node tree[2 * tsize];

void push(int v) {
    if (v < tsize && tree[v].add) {
        tree[v * 2].add += tree[v].add;
        tree[v * 2].minval += tree[v].add;
        tree[v * 2 + 1].add += tree[v].add;
        tree[v * 2 + 1].minval += tree[v].add;
        tree[v].add = 0;
    }
}

int getsum(int right) {
    int sum = 0;
    for (int l = tsize, r = right + tsize; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sum += tree[l++].can_count;
        if (r & 1) sum += tree[--r].can_count;
    }
    return sum;
}

void update_one(int pos, int v, int tl, int tr) {
    if (pos < tl || pos > tr) return;
    push(v);
    if (tl == tr) {
        tree[v].minval = -inf;
        return;
    }
    int tm = (tl + tr) / 2;
    update_one(pos, v * 2, tl, tm);
    update_one(pos, v * 2 + 1, tm + 1, tr);
    tree[v].minval = min(tree[v * 2].minval, tree[v * 2 + 1].minval);
}

void remove_negative(int v) {
    push(v);
    if (v >= tsize) {
        tree[v].minval = inf;
        tree[v].can_count = 0;
        return;
    }
    if (tree[v * 2].minval < 0) {
        tree[v * 2 + 1].minval -= 1;
        tree[v * 2 + 1].add -= 1;
        remove_negative(v * 2);
    } else {
        remove_negative(v * 2 + 1);
    }
    tree[v].minval = min(tree[v * 2].minval, tree[v * 2 + 1].minval);
    tree[v].can_count = tree[v * 2].can_count + tree[v * 2 + 1].can_count;
}

struct Query {
    int y, id;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int d = 0;
    for (int i = 0; i < n; ++i) {
        int val = a[i] - (i + 1);
        if (val > 0 || val + d < 0) {
            tree[tsize + i].can_count = 0;
            tree[tsize + i].minval = inf;
        } else {
            tree[tsize + i].can_count = 1;
            tree[tsize + i].minval = val + d;
            ++d;
        }
    }
    for (int i = n; i < tsize; ++i) {
        tree[tsize + i].can_count = 0;
        tree[tsize + i].minval = inf;
    }
    for (int v = tsize - 1; v > 0; --v) {
        tree[v].minval = min(tree[v * 2].minval, tree[v * 2 + 1].minval);
        tree[v].can_count = tree[v * 2].can_count + tree[v * 2 + 1].can_count;
    }
    vector<vector<Query>> queries(n);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        queries[x].push_back(Query{y, i});
    }
    vector<int> ans(q, -100);
    for (int x = 0; x < n; ++x) {
        for (auto query: queries[x]) {
            ans[query.id] = getsum(n - query.y);
        }
        if (!tree[tsize + x].can_count) continue;
        update_one(x, 1, 0, tsize - 1); // set minval -inf
        while (tree[1].minval < 0) {
            remove_negative(1);
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

	solve();

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}