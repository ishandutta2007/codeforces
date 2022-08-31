#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

// need to setmin, + maintain external array
struct T { 
    int one, two; // first max, second max
    int cnt; // count of first max
    int lzy;

    T() {
        one = two = -1; // if second max doesn't exist set to -1
        cnt = 0;
        lzy = MOD;
    }

    T(int x) {
        one = x, two = -1;
        cnt = 1;
        lzy = MOD;
    }
} t[4 * N];

int n;
ll aux[4 * N], aux_lzy[4 * N];
void aux_push(int v, int tl, int tr, ll x) {
    aux[v] += x * (tr - tl + 1);
    if (tl != tr)
        aux_lzy[2*v] += x, aux_lzy[2*v+1] += x;
}
void aux_app(int v, int tl, int tr) {
    aux_push(v, tl, tr, aux_lzy[v]), aux_lzy[v] = 0;
}
ll _aux_qry(int v, int tl, int tr, int l, int r) {
    aux_app(v, tl, tr);
    if (r < tl || l > tr) return 0;
    if (l <= tl && tr <= r) return aux[v];
    int tm = (tl + tr) / 2;
    return _aux_qry(2*v, tl, tm, l, r) + _aux_qry(2*v+1, tm+1, tr, l, r);
}
ll aux_qry(int l, int r) {
    return _aux_qry(1, 0, n-1, l, r);
}
void _aux_norm_upd(int v, int tl, int tr, int l, int r, int x) {
    aux_app(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        aux_push(v, tl, tr, x);
        return;
    }
    int tm = (tl + tr) / 2;
    _aux_norm_upd(2*v, tl, tm, l, r, x), _aux_norm_upd(2*v+1, tm+1, tr, l, r, x);
    aux[v] = aux[2*v] + aux[2*v+1];
}
void aux_norm_upd(int l, int r, int x) {
    _aux_norm_upd(1, 0, n-1, l, r, x);
    // for (int i = l; i <= r; i++) aux[i] += x;
}

void aux_upd(int x, int cnt, int y) { // change cnt occurences of x to y
    // cerr << "aux_upd: " << x << ' ' << cnt << ' ' << y << endl;
    if (y < x) {
        aux_norm_upd(y+1, x, -cnt);
    } else {
        aux_norm_upd(x+1, y, cnt);
    }
}
void setmin(int& a, int b) {
    a = min(a, b);
}
void push(int v, int tl, int tr, int x) {
    if (x >= t[v].one) return;
    assert(t[v].two < x && x < t[v].one);
    t[v].one = x;
    if (tl != tr) {
        setmin(t[2*v].lzy, x);
        setmin(t[2*v+1].lzy, x);
    }
}
T comb(T l, T r) {
    T ans; ans.one = max(l.one, r.one);
    if (l.one == ans.one) ans.cnt += l.cnt;
    if (r.one == ans.one) ans.cnt += r.cnt;
    for (int x : {l.one, l.two, r.one, r.two}) if (x < ans.one) {
        ans.two = max(ans.two, x);
    }
    return ans;
}
void upd(int v, int tl, int tr, int l, int r, int x) { // only update the external array in this function
    if (t[v].lzy != MOD) {
        push(v, tl, tr, t[v].lzy);
        t[v].lzy = MOD;
    }
    if (x >= t[v].lzy) return; // this update is useless
    // cerr << "on node upd: " << v << ' ' << tl << ' ' << tr << ' ' << t[v].lzy << ' ' << t[v].one << ' ' << t[v].two << ' ' << t[v].cnt << endl;
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        if (x >= t[v].one) return;
        if (t[v].two < x && x < t[v].one) {
            // update the auxillary array
            // cerr << "\t> " << tl << ' ' << tr << ' ' << t[v].one << ' ' << t[v].cnt << ' ' << t[v].two << endl;
            aux_upd(t[v].one, t[v].cnt, x);
            // cerr << "ONE\n";
            push(v, tl, tr, x);
            // cerr << "TWO\n";
            return;
        }
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = comb(t[2*v], t[2*v+1]);
}
void point(int v, int tl, int tr, int p, int x) {
    // cerr << "on node point: " << v << ' ' << tl << ' ' << tr << ' ' << t[v].lzy << ' ' << t[v].one << ' ' << t[v].two << ' ' << t[v].cnt << endl;
    if (t[v].lzy != MOD) {
        push(v, tl, tr, t[v].lzy);
        t[v].lzy = MOD;
    }
    if (p < tl || p > tr) return;
    if (tl == tr) {
        aux_upd(t[v].one, t[v].cnt, x);
        t[v] = T(x);
        return;
    }
    int tm = (tl + tr) / 2;
    point(2*v, tl, tm, p, x), point(2*v+1, tm+1, tr, p, x);
    t[v] = comb(t[2*v], t[2*v+1]);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = T(tl);
        aux_norm_upd(tl, tl, 1);
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm), build(2*v+1, tm+1, tr);
        t[v] = comb(t[2*v], t[2*v+1]);
    }
}
void solve() {
    int q; cin >> n >> q;
    build(1, 0, n-1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int c, r; cin >> c >> r, --c, --r;
            // cerr << "start upd\n";
            point(1, 0, n-1, c, r);
            // for (int i = 0; i < n; i++) cerr << aux[i] << ' ';
            // cerr << endl;
            if (c > 0) {
                upd(1, 0, n-1, 0, c-1, c-1);
            }
            // for (int i = 0; i < n; i++) cerr << aux[i] << ' ';
            // cerr << endl;
        } else {
            int l, r; cin >> l >> r, --l, --r;
            cout << aux_qry(l, r) << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}