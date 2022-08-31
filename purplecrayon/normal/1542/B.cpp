#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> po{1};
    if (a > 1) {
        while (po.back() <= n) po.push_back(po.back()*a);
    }
    for (auto x : po) if (x <= n && (x%b) == (n%b)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}