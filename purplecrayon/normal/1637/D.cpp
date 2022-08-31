#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    // minimize sum{a}^2 + sum{b}^2
    // make a closest to (sum{a} + sum{b}) / 2
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        sum += b[i] - a[i];
    }
    int need = sum / 2;
    vector<int> dp(need + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = b[i-1] - a[i-1];
        for (int j = need; j >= x; j--) {
            if (dp[j] == -1 && dp[j-x] != -1) {
                dp[j] = i;
            }
        }
    }
    int use = 0;
    for (int i = 0; i <= need; i++) if (dp[i] != -1) use = i;

    vector<int> take;
    while (use) {
        int c = dp[use];
        take.push_back(c-1);
        use -= b[c-1] - a[c-1];
    }
    for (int c : take) swap(a[c], b[c]);

    auto cost = [&](vector<int> v) {
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)
            ans += (v[i] + v[j]) * (v[i] + v[j]);

        return ans;
    };

    cout << cost(a) + cost(b) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}