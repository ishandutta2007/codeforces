#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 2, m;
    cin >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            cnt_a += a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            cnt_b += b[i][j];
        }
    }
    if (cnt_a != cnt_b) {
        cout << -1 << endl;
        return 0;
    }
    int bal1 = 0, bal2 = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        bal1 += b[0][i] - a[0][i];
        bal2 += b[1][i] - a[1][i];
        while (bal1 > 0 && bal2 < 0) {
            ans++;
            bal1--;
            bal2++;
        }
        while (bal1 < 0 && bal2 > 0) {
            ans++;
            bal1++;
            bal2--;
        }
        ans += abs(bal1) + abs(bal2);
    }
    cout << ans << endl;
    return 0;
}