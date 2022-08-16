#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    ll a, b, w, x, c; cin >> a >> b >> w >> x >> c;
    if (c <= a) { cout << 0 << '\n'; return; }
    cout << (x*(c-a)+w-b-x-1)/(w-x)-a+c << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}