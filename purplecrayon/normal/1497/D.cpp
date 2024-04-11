#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<long long> s(n), tag(n), dp(n, 0);
        for (int i = 0; i < n; ++i) cin >> tag[i];
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int j = 1; j < n; ++j) {
            for (int i = j-1; i >= 0; --i) {
                if (tag[i] == tag[j]) continue;
                long long dpi = dp[i], dpj = dp[j], p = abs(s[i]-s[j]);
                dp[i] = max(dp[i], dpj + p);
                dp[j] = max(dp[j], dpi + p);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}