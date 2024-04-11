#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    ll ans = 0;
    for (int i = 1; i < n; i++) ans = max(ans, a[i]*a[i-1]);
   cout << ans << '\n'; 
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}