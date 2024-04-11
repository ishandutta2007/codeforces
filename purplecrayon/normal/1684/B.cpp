#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll x = (b * ll(1e9) + a), y = b, z = c;
    cout << x << ' ' << y << ' ' << z << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}