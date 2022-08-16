#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    ll n, a, b, p, q; cin >> n >> a >> b >> p >> q;
    ll both = n / std::lcm(a, b);
    ll one = n / a - both, two = n / b - both;
    cout << one * p + two * q + both * max(p, q) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}