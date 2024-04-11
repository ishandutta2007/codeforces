#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 20, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    // only touch the first 1's and the last 0's
    // if i touch the first k 1's

    if (is_sorted(a.begin(), a.end())) {
        cout << "0\n";
        return;
    }

    vector<int> cnt_z(n + 1);
    for (int i = n-1; i >= 0; i--) {
        cnt_z[i] = (a[i] == 0) + cnt_z[i+1];
    }

    vector<int> ones;
    for (int i = 0; i < n; i++) if (a[i])
        ones.push_back(i);

    int ans = sz(ones);
    for (int k = 0; k < sz(ones); k++) {
        ans = min(ans, k + max(0, cnt_z[ones[k]+1] - k));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}