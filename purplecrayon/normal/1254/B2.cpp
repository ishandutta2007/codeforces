#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;
const ll INF = 1e18+10;

vector<pair<ll, int>> get_pf_big(ll n){
    vector<pair<ll, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}

int n;
ll a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = a[i] + (i ? a[i-1] : 0);
    ll ans = INF;
    for (auto p : get_pf_big(a[n-1])) {
        ll cur = 0, x = p.first;
        for (int i = 0; i < n-1; i++) cur += min(a[i]%x, x-a[i]%x);
        ans = min(ans, cur);
    }
    cout << (ans >= INF ? -1 : ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}