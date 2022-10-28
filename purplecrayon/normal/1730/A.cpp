#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

void solve() {
    int n, c; cin >> n >> c;
    map<int, int> cnt;
    while (n--) {
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (auto& [x, k] : cnt) {
        ans += min(k, c);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}