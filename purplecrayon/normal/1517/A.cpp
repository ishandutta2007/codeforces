#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    ll n; cin >> n;
    if (n%2050){ cout << -1 << '\n'; return; }
    string x = to_string(n/2050);
    int ans = 0;
    for (auto c : x) ans += c - '0';
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}