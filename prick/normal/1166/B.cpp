#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int k;
    cin >> k;
    int n = 0, m = 0;
    for (int i = 1; i <= k; ++i) {
        if (k % i == 0 && i >= 5 && k / i >= 5) {
            n = i;
            m = k / i;
            break;
        }
    }
    if (n == 0) {
        cout << -1 << '\n';
        return 0;
    }
    string ans(k, 'a');
    string vowels = "aeoui";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[m * i + j] = vowels[(i + j) % 5];
        }
    }
    cout << ans << '\n';
}