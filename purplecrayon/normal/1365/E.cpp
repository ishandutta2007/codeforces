#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 60, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& it : a) cin >> it;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
        for (int j = i+1; j < n; j++){ 
            ans = max(ans, a[i]|a[j]);
            for (int k = j+1; k < n; k++) {
                ans = max(ans, a[i]|a[j]|a[k]);
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}