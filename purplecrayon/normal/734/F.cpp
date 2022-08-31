#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<ll> b(n); for (auto& it : b) cin >> it;
    vector<ll> c(n); for (auto& it : c) cin >> it;
    vector<ll> x(n); for (int i = 0; i < n; i++) x[i] = c[i]+b[i];
    ll sm = 0;
    for (auto& it : x) sm += it;
    if (sm%(2*n)){ cout << -1 << '\n'; return; }
    sm /= 2*n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        ll v = x[i]-sm;
        if (v < 0 || v%n){ cout << -1 << '\n'; return; }
        a[i] = v/n;
    }
    ll cnt[32]={};
    for (int i = 0; i < n; i++) for (int j = 0; j < 32; j++) cnt[j] += (a[i]>>j)&1;
    for (int i = 0; i < n; i++) {
        ll bi = 0, ci = 0;
        for (int j = 0; j < 32; j++) {
            if ((a[i]>>j)&1) bi += cnt[j]<<j, ci += ll(n)<<j;
            else ci += cnt[j]<<j;
        }
        if (bi != b[i] || ci != c[i]){ cout << -1 << '\n'; return; }
    }
    for (auto c : a) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}