#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

// abs(one[i] - two[i])
// abs(ps_one[i], ps_two[i])

// at most one vert swap per position?
// vert swap changes ^^ by -2 potentially, otherwise increases, otherwise no point in swapping
// obviously a lower bound, is it achievable

auto read(int n) {
    vector<vector<int>> a(2, vector<int>(n));
    for (auto& r : a) for (auto& c : r) cin >> c;
    return a;
}
int sum(auto a) {
    int ans = 0;
    for (auto r : a) for (auto c : r) ans += c;
    return ans;
}
void solve() {
    int n; cin >> n;
    auto a = read(n), b = read(n);
    if (sum(a) != sum(b)) {
        cout << -1 << '\n';
        return;
    }
    int one[2] = {}, two[2] = {};
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        one[0] += a[0][i], one[1] += a[1][i];
        two[0] += b[0][i], two[1] += b[1][i];

        ar<ll, 2> cur = {abs(one[0] - two[0]) + abs(one[1] - two[1]), 0};
        for (int x : {-1, 1}) {
            int y = -x;
            ll v = abs((one[0] + x) - two[0]) + abs((one[1] + y) - two[1]) + 1;
            cur = min(cur, ar<ll, 2>{v, x});
        }
        one[0] += cur[1], one[1] -= cur[1];
        ans += abs(one[0] - two[0]) + abs(one[1] - two[1]) + abs(cur[1]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}