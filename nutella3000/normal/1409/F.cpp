#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const int inf = 1e10;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 2, vector<int>(n + 2)));

    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= k + 1;j++) {
            for(int c = 0;c <= n + 1;c++) {
                dp[i][j][c] = -inf;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= k;j++) {
            for(int c = 0;c <= n;c++) {
                if (i == 0 && c == 0) dp[i][j][c] = 0;
                

                dp[i + 1][j][c + (s[i] == t[0])] = max(dp[i + 1][j][c + (s[i] == t[0])], dp[i][j][c] + (s[i] == t[1]) * c);
                dp[i + 1][j + 1][c + 1] = max(dp[i + 1][j + 1][c + 1], dp[i][j][c] + (t[0] == t[1]) * c);
                dp[i + 1][j + 1][c] = max(dp[i + 1][j + 1][c], dp[i][j][c] + c);

                //cout << i << " " << j << " " << c << " " << dp[i][j][c] << endl;
            }
        }
    }

    cout << dp[n][k][max_element(all(dp[n][k])) - dp[n][k].begin()] << endl;
}