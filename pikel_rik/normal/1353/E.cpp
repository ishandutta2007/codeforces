#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 998244353;
const int inf = 2e9 + 5;

int solve(const string &s) {
    int n = s.length();
    vector<int> pref(n + 1);

    for (int i = 0; i < n; i++)
        pref[i+1] = pref[i] + (s[i] == '1');

    int dp[n];
    dp[0] = (s[0] != '1');

    for (int i = 1; i < n; i++)
        dp[i] = min(pref[i] + (s[i] != '1'), dp[i-1] + (s[i] != '1'));

    int ans = inf;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[i] + pref[n] - pref[i+1]);

    return min(ans, pref[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<string> str(k);
        int total = count(all(s), '1');

        for (int i = 0; i < n; i++)
            str[i % k] += s[i];

        int ans = inf;
        for (int i = 0; i < k; i++)
            ans = min(ans, solve(str[i]) + total - count(all(str[i]), '1'));

        cout << ans << "\n";
    }
    return 0;
}