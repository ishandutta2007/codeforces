#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    // lasrgest subsequence s.t. for all of *it's* subsequences
    //      big <= small
    //      considering subsequences of length 3 should be enough
    //
    //      for big to be greater than small:
    //      a, b, c
    //
    //      b > (a + b + c) / 3
    //      b > a / 3 + b / 3 + c / 3
    //
    //      2 * a[i] <= a[0] + a[i+1]
    //      a[i+1] >= 2 * a[i] - a[0]

    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    int ans = 0;
    for (int start = 0; start < n; start++) {
        if (start && a[start] == a[start-1]) continue;
        int cur = 0;
        int use = start;
        while (use < n) {
            cur++;
            use = max<int>(use + 1, std::lower_bound(a.begin(), a.end(), a[use] * 2 - a[start]) - a.begin());
        }
        ans = max(ans, cur);
    }
    cout << n - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}