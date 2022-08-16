#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

ll qry(ll l, ll r) {
    cout << "? " << l+1 << ' ' << r+1 << endl;
    ll x; cin >> x;
    return x;
}
void solve() {
    ll n; cin >> n;

    ll last_rev = -1;

    {
        ll lo = 0, hi = n, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            ll x = qry(mid, n-1);
            if (x) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        last_rev = lo + 1;
    }
    ll size_last = qry(0, last_rev) - qry(0, last_rev - 1) + 1;
    ll inv_first = qry(0, n - 1) - size_last * (size_last - 1) / 2;
    ll size_first = -1;
    {
        ll lo = 0, hi = n, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (mid * (mid - 1) / 2 <= inv_first) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        size_first = lo;
    }
    ll k = last_rev;
    ll j = k - size_last + 1;
    ll i = j - size_first;
    cout << "! " << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}