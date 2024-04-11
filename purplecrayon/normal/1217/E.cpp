#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;
const int INF = 1e9+10;

ar<int, 2> merge(ar<int, 2> a, ar<int, 2> b) {
    if (a > b) swap(a, b);
    return ar<int, 2>{a[0], min(a[1], b[0])};
}

const int D = 11;
struct T {
    ar<int, 2> dig[D];
    void init() {
        for (auto& c : dig) c.fill(INF);
    }
} t[4*MAXN];

T make_empty(int x) {
    int v = x;

    T ans; ans.init();
    for (int i = 0; i < D; i++, v /= 10) {
        int c = v%10;
        if (c) ans.dig[i][0] = x;
    }
    return ans;
}
T merge(T l, T r) {
    T ans;
    for (int i = 0; i < D; i++) ans.dig[i] = merge(l.dig[i], r.dig[i]);
    return ans;
}
int get(T c) {
    int ans = 2*INF;
    for (int i = 0; i < D; i++) if (c.dig[i][1] != INF) ans = min(ans, c.dig[i][0]+c.dig[i][1]);
    return (ans == 2*INF ? -1 : ans);
}

int n, q;
int a[MAXN];

void bld(int v, int tl, int tr) {
    if (tl == tr) t[v] = make_empty(a[tl]);
    else {
        int tm=(tl+tr)/2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
        t[v] = merge(t[2*v], t[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int pos, int x) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        t[v] = make_empty(x);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, x), upd(2*v+1, tm+1, tr, pos, x);
    t[v] = merge(t[2*v], t[2*v+1]);
}
T qry(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return make_empty(0);
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return merge(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    bld(1, 0, n-1);
    cerr << get(qry(1, 0, n-1, 2, 3)) << '\n';
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int pos, x; cin >> pos >> x, --pos;
            upd(1, 0, n-1, pos, x);
        }
        if (t == 2) {
            int l, r; cin >> l >> r, --l, --r;
            cout << get(qry(1, 0, n-1, l, r)) << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}