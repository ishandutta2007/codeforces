#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const ll INF = (long long) 1e18 + 50;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
void solve() {
    ll ans = -1;
    for (int i = 2; i <= 26; i++) {
        int a = 1, b = i;
        if (a == b) continue;

        cout << "? " << a << ' ' << b << endl;
        ll x; cin >> x;
        if (x == -1) {
            cout << "! " << i-1 << endl;
            return;
        }
        cout << "? " << b << ' ' << a << endl;
        ll y; cin >> y;

        ans = x + y;
        if (x != y) {
            cout << "! " << ans << endl;
            return;
        }
    }
    cout << "! " << ans << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}