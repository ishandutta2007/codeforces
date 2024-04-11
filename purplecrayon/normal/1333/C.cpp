#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    map<ll, int> mp; vector<ar<ll, 2>> v;
    ll ps = 0; mp[0] = -1;
    for (int i = 0; i < n; i++){
        ps += a[i];
        if (mp.count(ps)) v.push_back(ar<ll, 2>{mp[ps]+1, i});
        mp[ps] = i;
    }
    sort(v.begin(), v.end());
    ll ans = 0; ll ptr = sz(v)-1, mn = n;
    for (int i = n-1; i >= 0; i--){
        while (ptr >= 0 && v[ptr][0] >= i) mn = min(mn, v[ptr][1]), ptr--;
        ans += mn-i;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}