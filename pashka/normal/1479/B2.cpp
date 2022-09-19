#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> last(n + 1, -1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> aa;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) aa.push_back(a[i]);
    }
    a = aa;
    n = a.size();
    vector<int> dp(n + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = mx;
        if (last[a[i]] != -1) {
            dp[i] = max(dp[i], dp[last[a[i]] + 1] + 1);
        }
//        cout << a[i] << " " << last[a[i]] << " " << dp[i] << "\n";
        last[a[i]] = i;
        mx = max(mx, dp[i]);
    }
    cout << n - mx << "\n";
    return 0;
}