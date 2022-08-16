#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
        int x; cin >> x;
        mp[abs(x)]++;
    }
    int ans = 0;
    for (auto [x, k] : mp) {
        if (x == 0) ans += min(k, 1);
        else ans += min(k, 2);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}