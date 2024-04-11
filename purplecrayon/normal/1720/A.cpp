#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll one = a * d, two = b * c;
    if (one == two) cout << 0 << '\n';
    else if (a == 0 || c == 0 || one % two == 0 || two % one == 0) cout << 1 << '\n';
    else cout << 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}