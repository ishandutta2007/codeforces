#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int L = 19;

int n, q, a[N];
ll t[4*N];
bool rev[L];

void upd(int v, int tl, int tr, int d, int i, int x) {
    if (i < tl || i > tr) return;
    if (tl == tr) {
        t[v] = x;
        return;
    }
    if (rev[d]) i = tr - i + tl;
    int tm = (tl + tr) / 2;
    if (i <= tm) upd(2*v, tl, tm, d-1, i, x);
    else upd(2*v+1, tm+1, tr, d-1, i, x);
    t[v] = t[2*v] + t[2*v+1];
}
ll qry(int v, int tl, int tr, int d, int l, int r) {
    if (r < tl || l > tr) return 0;
    if (l == tl && tr == r) return t[v];

    int tm = (tl + tr) / 2;
    if (rev[d])
        tie(l, r) = std::make_pair(tr - r + tl, tr - l + tl);

    return qry(2*v, tl, tm, d-1, l, min(tm, r)) + qry(2*v+1, tm+1, tr, d-1, max(tm+1, l), r);
}
void solve() {
    cin >> n >> q;
    int m = 1 << n;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) upd(1, 0, m-1, n, i, a[i]);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x, --i;
            upd(1, 0, m-1, n, i, x);
        } else if (t == 2) {
            int k; cin >> k;
            rev[k] ^= 1;
        } else if (t == 3) {
            int k; cin >> k;
            rev[k] ^= 1, rev[k+1] ^= 1;
        } else {
            int l, r; cin >> l >> r, --l, --r;
            cout << qry(1, 0, m-1, n, l, r) << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}