#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    ll m = *max_element(a.begin(), a.end());
    ll sum = std::accumulate(a.begin(), a.end(), 0LL);
    if (m == 0) cout << 0 << '\n';
    else if (m * 2 <= sum) cout << 1 << '\n';
    else cout << 2 * m - sum << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}