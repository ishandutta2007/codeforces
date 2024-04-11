#include "bits/stdc++.h"
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> ps(n);
    for (int i = 0; i < n; i++){
        ps[i]=a[i];
        if (i) ps[i] ^= ps[i-1];
    }
    //ps[mid]^ps[l-1] == ps[r]^ps[mid]
    //ps[r]==ps[l-1]
    map<int, int> mp[2];
    ll ans=0; mp[1][0]++;
    for (int i = 0; i < n; i++){
        ans += mp[i&1][ps[i]];
        mp[i&1][ps[i]]++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}