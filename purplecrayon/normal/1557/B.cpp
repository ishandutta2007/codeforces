#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> loc(n); iota(loc.begin(), loc.end(), 0);
    sort(loc.begin(), loc.end(), [&](int i, int j){ return a[i] < a[j]; });

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (loc[i] != loc[i-1]+1) ans++;
    }
    if (ans <= k) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}