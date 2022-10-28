#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    ll w1, h1, w2, h2; cin >> w1 >> h1 >> w2 >> h2;
    ll green = 2*h1+2*w1+4;
    green -= w2;
    green += h2*2+w2;
    cout << green << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}