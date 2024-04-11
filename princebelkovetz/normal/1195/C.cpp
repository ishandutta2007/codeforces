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
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector <vector <int>> dp(n + 1, vector <int> (2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            dp[i][0] = a[i - 1];
            dp[i][1] = b[i - 1];
        }
        else {
            dp[i][0] = max(dp[i - 1][1] + a[i - 1], dp[i - 2][1] + a[i - 1]);
            dp[i][1] = max(dp[i - 1][0] + b[i - 1], dp[i - 2][0] + b[i - 1]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}