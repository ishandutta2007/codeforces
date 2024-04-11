//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    string s;
    cin >> s;
    if (sz(s) == 1)
        return cout << 0 << '\n', 0;
    if (sz(s) == 2)
        return cout << (s[0] == s[1]) << '\n', 0;
    int dp[2][26][26];
    const int INF = 1000 * 1000 * 1000;
    for (int j = 0; j < 26; j++)
        for (int k = 0; k < 26; k++)
            if (j == k)
                dp[0][j][k] = INF;
            else
                dp[0][j][k] = (s[0] != 'a' + j) + (s[1] != 'a' + k);
    int cur = 0,
        prv = 1;
    int le[27][26];
    int ri[27][26];
    for (int i = 2; i < sz(s); i++) {
        swap(cur, prv);
        for (int k = 0; k < 26; k++) {
            le[0][k] = INF;
            for (int j = 0; j < 26; j++)
                le[j + 1][k] = min(le[j][k], dp[prv][j][k]);
            ri[26][k] = INF;
            for (int j = 26 - 1; j >= 0; j--)
                ri[j][k] = min(ri[j + 1][k], dp[prv][j][k]);
        }
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                if (j == k)
                    dp[cur][j][k] = INF;
                else
                    dp[cur][j][k] = min(le[k][j], ri[k + 1][j])
                        + (s[i] != 'a' + k);
    }
    int ans = INF;
    for (int j = 0; j < 26; j++)
        for (int k = 0; k < 26; k++)
            smin(ans, dp[cur][j][k]);
    cout << ans << '\n';
    return 0;
}