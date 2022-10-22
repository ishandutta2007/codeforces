#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int n; cin >> n;
    vector <int> a(n), dp(n + 1, 0), dp2(n + 1, n - 1);
    for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << 1; return 0;
    }
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max(dp[i], i);
        for (int j = dp[i + 1] + 1; j < n; ++j) {
            if (a[j] <= a[j - 1]) break;
            dp[i + 1]++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        dp2[i] = min(dp2[i + 1], i);
        for (int j = dp2[i] - 1; j >= 0; j--) {
            if (a[j] >= a[j + 1]) break;
            dp2[i]--;
        }
    }
    //for (auto x : dp) cout << x << " ";
    //cout << endl;

    //for (auto x : dp2) cout << x << " ";
    //cout << endl;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int left = 0, right = 0;
        if (i == 0) right = dp[2];
        else if (i == n - 1) left = n - 1 - dp2[i - 1];
        else {
            right = dp[i + 2] - i;
            left = i - dp2[i - 1];
        }
        //debug(left) debug(right);
        if (i == 0 or i == n - 1 or a[i - 1] + 1 < a[i + 1]) ans = max(ans, left + right + 1);
        else ans = max(ans, max(left + 1, right + 1));
        //debug(ans)
    }


    cout << ans;
}