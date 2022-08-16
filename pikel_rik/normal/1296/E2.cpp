#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, dp[N], mxdp[26];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++) dp[i] = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            dp[i] = max(dp[i], 1 + mxdp[j]);
        }
        mxdp[s[i] - 'a'] = dp[i];
    }

    cout << *max_element(dp, dp + n) << "\n";
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    return 0;
}