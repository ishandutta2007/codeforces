#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int D = 31;

struct basis {
    int n = 0, bas[D];

    void init(){ memset(bas, 0, sizeof(bas)); n = 0; }
    void add(int x) {
        if (!x) return;
        for (int i = 0; i < D; i++) if ((x>>i)&1) {
            if (!bas[i]) {
                bas[i] = x, n++;
                return;
            }
            x ^= bas[i];
        }
    }
    void merge(basis b) {
        for (int i = 0; i < D; i++) if (b.bas[i])
            add(b.bas[i]);
    }
} t[4*MAXN];

int n, q, a[MAXN], b[MAXN];

int bit[MAXN];
int qry(int i){ int ans=0; for (++i; i; i -= i & -i) ans ^= bit[i]; return ans; }
void _upd(int i, int x){ for (++i; i <= n; i += i & -i) bit[i] ^= x; }
void upd(int l, int r, int x){ _upd(l, x), _upd(r+1, x); }

void bld(int v, int tl, int tr) {
    t[v].init();
    if (tl == tr) t[v].add(b[tl]);
    else {
        int tm=(tl+tr)/2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
        t[v].merge(t[2*v]), t[v].merge(t[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int pos, int x) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        b[tl] ^= x;
        t[v].init(), t[v].add(b[tl]);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, x), upd(2*v+1, tm+1, tr, pos, x);
    t[v].init(), t[v].merge(t[2*v]), t[v].merge(t[2*v+1]);
}
basis qry(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    basis ans; ans.init();
    if (l <= tm)
        ans.merge(qry(2*v, tl, tm, l, r));
    if (tm < r)
        ans.merge(qry(2*v+1, tm+1, tr, l, r));
    return ans;
}

void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i], upd(i, i, a[i]);
    for (int i = 0; i < n-1; i++) b[i] = a[i]^a[i+1];

    if (n > 1) bld(1, 0, n-2);
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int l, r; ll x; cin >> l >> r >> x, --l, --r;
            if (l) upd(1, 0, n-2, l-1, x);
            if (r < n-1) upd(1, 0, n-2, r, x);
            upd(l, r, x); //bit upd
        } else if (ty == 2) {
            int l, r; cin >> l >> r, --l, --r;

            basis b; b.init();
            if (l < r) b = qry(1, 0, n-2, l, r-1);
            b.add(qry(l));

            cout << (1ll<<b.n) << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}