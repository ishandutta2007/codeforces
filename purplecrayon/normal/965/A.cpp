#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;
const ll INF = 1e18+10;

ll ceil_div(ll x, ll y){ return (x+y-1)/y; }
void solve(){
    ll k, n, s, p; cin >> k >> n >> s >> p;
    cout << ceil_div(k*ceil_div(n, s), p);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}