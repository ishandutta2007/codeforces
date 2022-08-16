#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<ll> b(n); for (auto& x : b) cin >> x;
    vector<ll> a(n);

    ll x = 0;
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + x;
        x = max(x, a[i]);
    }
    for (auto& c : a) cout << c << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}