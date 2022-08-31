#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    ll x, y; cin >> x >> y;
    // ll x = rand() % 100 * 2 + 2, y = rand() % 100 * 2 + 2;
    // cerr << x << ' ' << y << endl;
    ll n = -1;
    if (x == y)  n = x; 
    else if (x > y) {
        n = x + y;
    } else {
        x = (y - x) / x * x + x;
        n = (x + y) / 2;
    }
    cout << n << '\n';
    assert(n % x == y % n);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}