#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;

void run() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), xo(n+1);
    vector<int> nx(n+1, n), pr(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        xo[i + 1] = xo[i] ^ a[i];

        pr[i] = a[i] != 0 ? i : (i ? pr[i-1] : -1);
    }
    for (int i = n-1; i >= 0; --i) {
        nx[i] = a[i] != 0 ? i : nx[i+1];
    }

    while (q--) {
        int l, r; cin >> l >> r; --l, --r;
        int x = xo[r+1] ^ xo[l];
        int res_l = l, res_r = r; 


        for (int ll_ = l;;) {

            int y = x;
            for (int rr = r;;) {
                if (rr - ll_ < res_r - res_l) {
                    res_l = ll_, res_r = rr;
                }
                if (rr == ll_) break;
                if ((a[rr] & y) != a[rr]) break;
                y ^= a[rr];
                rr = max(ll_, pr[rr-1]);
            }
            if (ll_ == r) break;
            if ((a[ll_] & x) != a[ll_]) break;
            x ^= a[ll_];
            ll_ = min(nx[ll_+1], r);
        }

        cout << res_l + 1 << " " << res_r + 1 << '\n';
    }
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}