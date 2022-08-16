#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    
    ll ans = 0;
    for (auto& [_, b] : mp) {
        ll cur = 0;
        for (int i = sz(b) - 1; i >= 0; i--) {
            ans += cur * (b[i] + 1);
            cur += n - b[i];
        }
    }
    cout << ans << '\n';

    // sum{ (i + 1) * (n - j) } over all pairs
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}