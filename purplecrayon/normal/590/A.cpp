#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

auto op(vector<int> a) {
    int n = sz(a);
    vector<int> ans(n); ans[0] = a[0], ans[n-1] = a[n-1];
    for (int i = 1; i < n-1; i++) {
        int sum = a[i-1] + a[i] + a[i+1];
        if (sum >= 2) ans[i] = 1;
        else ans[i] = 0;
    }
    return ans;
}
void pr(vector<int> a) {
    for (int x : a) cout << x << ' ';
    cout << '\n';
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (op(a) == a) {
        cout << 0 << '\n';
        pr(a);
        return;
    }
    a = op(a);
    vector<bool> has(n-1);
    for (int i = 0; i < n-1; i++) {
        if (a[i] == a[i+1])
            has[i] = 1;
    }
    assert(*std::max_element(has.begin(), has.end()));

    vector<pair<int, int>> ans(n, {n + 1, MOD});
    int p = -MOD;
    for (int i = 1; i < n-1; i++) {
        if (has[i-1] || has[i]) p = i;
        ans[i] = min(ans[i], {i - p, -1});
    }
    p = MOD;
    for (int i = n-1; i >= 1; i--) {
        if (has[i-1] || has[i]) p = i;
        ans[i] = min(ans[i], {p - i, +1});
    }
    cout << std::max_element(ans.begin() + 1, ans.end() - 1)->first + 1 << '\n';
    vector<int> v = a;
    for (int i = 1; i < n-1; i++) {
        int c = -1;
        if (ans[i].second == -1) c = i - ans[i].first;
        else c = i + ans[i].first;
        v[i] = a[c];
    }
    pr(v);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}