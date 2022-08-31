#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

int n;
ll add = 0;
vector<ll> odd;

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if ((x%2+2)%2 == 1) odd.push_back(x);
        else {
            if (x > 0) add += x;
        }
    }
    ll ans = -MOD;
    sort(odd.rbegin(), odd.rend());
    ll cur = 0;
    for (auto c : odd) {
        cur += c;
        if ((cur%2+2)%2 == 1) ans = max(ans, cur+add);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}