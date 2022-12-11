#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    
    if (a == b) {
        cout << 1 << ' ' << a << '\n';
        return;
    }
    
    vector<int> ans;
    ans.push_back(a);
    for (int k = 1, mul = 1; ; ++k, mul *= 2) {
        if (mul * (a + 1) > b) {
            cout << -1 << '\n';
            return;
        }
        ans.push_back(mul * (a + 1));
        if (b <= mul * (a + m)) {
            int r = b - mul * (a + 1);
            mul = max(1ll, mul / 2);
            for (int j = 1; j <= k; ++j, mul = max(1ll, mul / 2)) {
                int x = min(m - 1, r / mul);
                r -= mul * x;
                ans[j] += x;
                for (int t = j + 1, imul=1; t <= k; ++t, imul *= 2) {
                    ans[t] += x * imul;
                }
            }
            assert(r == 0);
            cout << k + 1 << ' ';
            for (auto i: ans) {
                cout << i << ' ';
            }
            cout << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
}