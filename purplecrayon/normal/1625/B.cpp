#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    int ans = -1;
    for (auto& [_, a] : mp) {
        for (int i = 1; i < sz(a); i++) {
            int x = a[i-1], y = a[i];
            ans = max(ans, x + n - y);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}