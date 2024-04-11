#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

struct T {
    int len = 0;
    int pre = 0, suff = 0;
    ll ans = 0;

    T() {}
    T(int x) {
        assert(x == 0 || x == 1);
        len = 1;
        pre = suff = ans = x;
    }
    friend T operator + (const T& a, const T& b) {
        T ans; ans.len = a.len + b.len;
        ans.pre = a.pre;
        if (a.pre == a.len) ans.pre += b.pre;

        ans.suff = b.suff;
        if (b.suff == b.len) ans.suff += a.suff;

        ans.ans = a.ans + b.ans;
        ans.ans += (long long) a.suff * b.pre;
        return ans;
    }
} t[4*MAXN];

int n, q, a[MAXN];
bool b[MAXN];

void upd(int v, int tl, int tr, int pos, int x) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        t[v] = T(x);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, pos, x), upd(2*v+1, tm+1, tr, pos, x);
    t[v] = t[2*v] + t[2*v+1];
}
T qry(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return T();
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return qry(2*v, tl, tm, l, r) + qry(2*v+1, tm+1, tr, l, r);
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        while (q--) {
            int t; cin >> t;
            int X, Y; cin >> X >> Y;
            if (t == 2) cout << 1 << '\n';
        }
        return;
    }

    for (int i = 0; i < n-1; i++) {
        b[i] = a[i] <= a[i+1];
        upd(1, 0, n-2, i, b[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int c, x; cin >> c >> x, --c;
            if (c > 0) {
                b[c-1] = a[c-1] <= x;
                upd(1, 0, n-2, c-1, b[c-1]);
            }
            if (c < n-1) {
                b[c] = x <= a[c+1];
                upd(1, 0, n-2, c, b[c]);
            }
            a[c] = x;
        } else {
            int l, r; cin >> l >> r, --l, --r;
            ll ans = r-l+1;
            if (l < r) ans += qry(1, 0, n-2, l, r-1).ans;
            cout << ans << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}