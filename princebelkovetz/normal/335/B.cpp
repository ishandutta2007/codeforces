#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
const int N = 2e3 + 6e2 + 5;
int dp[N][N];
signed main() {
    string s; cin >> s;
    int n = s.size();
    if (n >= 2600) {
        map <char, int> cnt;
        for (auto x : s) {
            cnt[x]++;
            if (cnt[x] == 100) {
                cout << string(100, x) << '\n';
                return 0;
            }
        }
        
    }
    else {
        for (int r = 0; r < n; ++r) {
            for (int l = r; l >= 0; --l) {
                if (l == r) dp[l][r] = 1;
                else {
                    dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                    if (s[l] == s[r])
                        dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
                }
            }
        }
        int l = 0, r = n - 1;
        string la, ra;
        while (l <= r) {
            if (l == r) {
                la += s[l];
                l++;
            }
            else if (dp[l][r] == dp[l + 1][r]) l++;
            else if (dp[l][r] == dp[l][r - 1]) r--;
            else {
                la += s[l], ra += s[r];
                l++, r--;
            }
        }
        reverse(ra.begin(), ra.end());
        string ans = la + ra;
        if (ans.size() > 100) {
            ans = ans.substr(0, 50) + ans.substr(ans.size() - 50, 50);
        }
        cout << ans << '\n';
    }
    return 0;
}