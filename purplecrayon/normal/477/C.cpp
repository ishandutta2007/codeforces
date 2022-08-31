#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;
const int M = 5e2+10;

void smax(int& a, int b) {
    a = max(a, b);
}

int n, m;
int dp[N][N];
string s, t;
int match[N];

void solve() {
    cin >> s >> t;
    n = sz(s), m = sz(t);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n && c < m; j++) {
            if (s[j] == t[c]) {
                c++;
            } else {
                match[i]++;
            }
        }
        if (c < m) match[i] = -1;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -MOD;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            smax(dp[i+1][j+1], dp[i][j]); // skip the next character
            smax(dp[i+1][j], dp[i][j]); // skip the next character when choosing but don't actually skip it
            if (match[i] != -1 && j + match[i] <= n) {
                smax(dp[i + m + match[i]][j + match[i]], dp[i][j] + 1);
            }
        }
    }
    for (int i = 0; i <= sz(s); i++) cout << dp[n][i] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}