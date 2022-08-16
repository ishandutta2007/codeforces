#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    for (auto& [_, k] : mp) if (sz(k) == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n);
    for (auto& [_, k] : mp) {
        for (int i = 0; i < sz(k); i++) {
            ans[k[i]] = k[(i + 1) % sz(k)];
        }
    }
    for (int x : ans) cout << x+1 << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}