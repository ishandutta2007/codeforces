#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int rep = 0; rep < k; rep++) {
        int m = sz(a);
        ans += a[m-1-k] / a[m-1];
        a.pop_back();
    }
    while (k--) a.pop_back();
    for (int x : a) ans += x;

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}