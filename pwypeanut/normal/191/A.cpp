#include <bits/stdc++.h>
using namespace std;

int N, dp[500005], mxlen[26];
string s[500005];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> s[i];
    int ans = 0;
    for (char start = 'a'; start <= 'z'; start++) {
        memset(dp, -63, sizeof(dp));
        memset(mxlen, -63, sizeof(mxlen));
        for (int i = 0; i < N; i++) {
            if (s[i][0] == start) dp[i] = s[i].length();
            dp[i] = max(mxlen[s[i][0] - 'a'] + (int)s[i].length(), dp[i]);
            mxlen[s[i][s[i].length() - 1] - 'a'] = max(mxlen[s[i][s[i].length() - 1] - 'a'], dp[i]);
            if (s[i][s[i].length() - 1] == start) {
                ans = max(ans, dp[i]);
            }
        }
    }
    printf("%d\n", ans);
}