#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

//i->i+1
//2, 1 2 3 4 5..z, z-1, z-2, z-3
//
//z -> 2*(z-1)
//10 -> 


struct SEG {
    int n;
    vector<int> a;
    ll t[4*MAXN];

    void bld(int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl+tr)/2;
            bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
            t[v] = t[2*v]+t[2*v+1];
        }
    }
    void upd(int v, int tl, int tr, int pos, ll x) {
        if (pos < tl || pos > tr) return;
        if (tl == tr){ t[v] = x; return; }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, pos, x), upd(2*v+1, tm+1, tr, pos, x);
        t[v] = t[2*v]+t[2*v+1];
    }
    void upd(int pos, ll x){ upd(1, 0, n-1, pos, x); }
    ll qry(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) return 0;
        if (l <= tl && tr <= r) return t[v];
        int tm=(tl+tr)/2;
        return qry(2*v, tl, tm, l, r)+qry(2*v+1, tm+1, tr, l, r);
    }
    ll qry(int l, int r){ return qry(1, 0, n-1, l, r); }
    void init(vector<int> b){ a = b; n = sz(a); bld(1, 0, n-1); }
};

const int MAXM = 10;
int n, q;
ll a[MAXN];
SEG ps[MAXM/2 + 1][MAXM];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= MAXM; i += 2) {
        for (int j = 0; j < i; j++) {
            vector<int> c(n+1);
            for (int k = 1; k <= n; k++) if (k%i == j) c[k] = a[k];
            ps[i/2][j].init(c);
        }
    }
    cin >> q;
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int pos, x; cin >> pos >> x;
            for (int i = 2; i <= MAXM; i += 2) {
                ps[i/2][pos%i].upd(pos, x);
            }
        } else {
            int l, r, z; cin >> l >> r >> z;

            int mod = 2*(z-1);

            ll ans = 0;
            for (int v = 0; v < mod; v++) {
                int x = -1;
                if (v == 0) x = 2;
                else if (v <= z) x = v;
                else x = 2*z-v;

                ans += ll(x)*ps[mod/2][(v+l-1+mod)%mod].qry(l, r);
            }
            cout << ans << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}