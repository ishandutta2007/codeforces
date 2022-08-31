#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<ar<int, 2>> a(k);
    for (auto& c : a) cin >> c[0], c[0]--;
    for (auto& c : a) cin >> c[1];

    vector<int> b(n, 2*MOD);
    for (auto& c : a) b[c[0]] = c[1];

    vector<int> ans(n, 2*MOD);
    int mn = 2*MOD;
    for (int i = 0; i < n; i++) {
        mn = min(mn, -i+b[i]);
        ans[i] = min(ans[i], i+mn);
    }
    mn = 2*MOD;
    for (int i = n-1; i >= 0; i--) {
        mn = min(mn, i+b[i]);
        ans[i] = min(ans[i], -i+mn);
    }
    for (auto x : ans) cout << x << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}