#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n); for (auto& x : p) cin >> x;
    int ans = 0;
    for (int i = 0; i < k; i++) ans += p[i] > k;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}