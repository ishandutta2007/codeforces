#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

struct Tree {
    int n;
    vector<int> t, lzy;

    Tree(int _n): n(_n) {
        t.resize(4 * n);
        lzy.resize(4 * n);
    }
    void push(int v, int tl, int tr, int x) {
        t[v] += x;
        if (tl != tr)
            lzy[2*v] += x,
            lzy[2*v+1] += x;
    }
    void app(int v, int tl, int tr) {
        push(v, tl, tr, lzy[v]), lzy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, int x) {
        app(v, tl, tr);
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r) {
            push(v, tl, tr, x);
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
        t[v] = min(t[2*v], t[2*v+1]);
    }
    int qry(int v, int tl, int tr, int l, int r) {
        app(v, tl, tr);
        if (r < tl || l > tr) return MOD;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return min(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
    }
    void upd(int l, int r, int x) {
        upd(1, 0, n-1, l, r, x);
    }
    int qry(int l, int r) {
        return qry(1, 0, n-1, l, r);
    }
};

int n, m;

void solve() {
    cin >> n >> m;
    vector<ar<int, 3>> a(n);
    for (auto& [l, r, w] : a) cin >> l >> r >> w, --l, --r;

    sort(a.begin(), a.end(), [&](auto one, auto two) { return one[2] < two[2]; }); // sort by weight

    Tree tree(m - 1);

    int ans = MOD;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && tree.qry(0, m-2) == 0) {
            auto [x, y, _] = a[r];
            tree.upd(x, y-1, +1);
            r++;
        }
        if (tree.qry(0, m-2)) {
            ans = min(ans, a[r-1][2] - a[l][2]);
        }
        auto [x, y, _] = a[l];
        tree.upd(x, y-1, -1);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}