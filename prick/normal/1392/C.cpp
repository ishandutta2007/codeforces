#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ans += max((int) 0, a[i] - a[i + 1]);
    }
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}