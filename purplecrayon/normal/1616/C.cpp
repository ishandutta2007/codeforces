#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> mp;
        for (int j = 0; j < n; j++) if (i != j) {
            int x = a[i] - a[j];
            int y = i - j;
            int g = std::gcd(abs(x), abs(y));
            x /= g, y /= g;
            mp[{x, y}]++;
        }
        for (auto& [_, k] : mp) ans = min(ans, n - 1 - k);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}