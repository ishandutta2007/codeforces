#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    int O = n;
    while (n--) {
        int x; cin >> x;
        mp[x]++;
    }
    int ans = sz(mp);
    if (ans % 2 != O % 2) ans--;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}