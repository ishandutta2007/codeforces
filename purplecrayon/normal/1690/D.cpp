#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        ps[i] = s[i] == 'W';
        if (i) ps[i] += ps[i-1];
    }
    auto sum = [&](int l, int r) { return ps[r] - (l ? ps[l-1] : 0); };
    int ans = n;
    for (int i = 0; i + k <= n; i++) {
        ans = min(ans, sum(i, i + k - 1));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}