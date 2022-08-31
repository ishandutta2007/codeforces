#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;

    map<int, int> mp;
    for (int x : a) mp[x]++;
    int cc = 0;
    for (auto& [_, k] : mp) k = cc++;
    for (auto& x : a) x = mp[x];

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[a[i]] = i;

    int ans = 1;
    for (int l = 0; l < n; l++) {
        for (int r = l+1; r < n; r++) {
            if (pos[r] < pos[r-1]) break;
            ans = max(ans, r - l + 1);
        }
    }
    cout << n - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}