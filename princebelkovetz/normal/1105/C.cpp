#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int n, l, r, mod = 1e9 + 7;
    cin >> n >> l >> r;
    vector <int> num(3);
    num[0] = r / 3 - (l - 1) / 3;
    num[2] = num[0];
    if (l % 3 == 0) num[2]--;
    if (r % 3 == 2) num[2]++;
    num[1] = num[2];
    if (l % 3 == 2) num[1]--;
    if (r % 3 == 1) num[1]++;
    vector <vector <int>> dp(n + 1, vector <int>(3));
    dp[1][0] = num[0];
    dp[1][1] = num[1];
    dp[1][2] = num[2];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i][0] + (dp[i - 1][0] * num[0]) % mod) % mod;
        dp[i][0] = (dp[i][0] + (dp[i - 1][1] * num[2]) % mod) % mod;
        dp[i][0] = (dp[i][0] + (dp[i - 1][2] * num[1]) % mod) % mod;
        dp[i][1] = (dp[i][1] + (dp[i - 1][0] * num[1]) % mod) % mod;
        dp[i][1] = (dp[i][1] + (dp[i - 1][1] * num[0]) % mod) % mod;
        dp[i][1] = (dp[i][1] + (dp[i - 1][2] * num[2]) % mod) % mod;
        dp[i][2] = (dp[i][2] + (dp[i - 1][0] * num[2]) % mod) % mod;
        dp[i][2] = (dp[i][2] + (dp[i - 1][1] * num[1]) % mod) % mod;
        dp[i][2] = (dp[i][2] + (dp[i - 1][2] * num[0]) % mod) % mod;
    }
    cout << dp[n][0] << "\n";
    return 0;
}