#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    if ((a + 2*b + 3*c) % 2 == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}