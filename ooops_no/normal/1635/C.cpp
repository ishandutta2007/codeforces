#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.pb(-INF);
    int j = n;
    vector<vector<int>> ans;
    for (int i = n - 2; i >= 0; i--) {
        if (i + 2 < n) {
            if (a[i + 2] > a[j]) {
                j = i + 2;
            }
        }
        if (a[i] > a[i + 1] && a[j] < 0) {
            cout << -1 << endl;
            return;
        }
        if (a[i] > a[i + 1]) {
            a[i] = a[i + 1] - a[j];
            ans.pb({i, i + 1, j});
        }
    }
    cout << ans.size() << endl;
    for (auto to : ans) {
        cout << to[0] + 1 << ' ' << to[1] + 1 << ' ' << to[2] + 1 << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}