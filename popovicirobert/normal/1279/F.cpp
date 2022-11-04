#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;



 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, k, l;
    cin >> n >> k >> l;

    string str;
    cin >> str;
    str = " " + str;

    vector<int> lower(n + 1), upper(n + 1);
    for (int i = 1; i <= n; i++) {
        lower[i] = lower[i - 1];
        upper[i] = upper[i - 1];
        if (str[i] >= 'a' && str[i] <= 'z') {
            lower[i]++;
        } else {
            upper[i]++;
        }
    }

    auto Solve = [&](const auto& sp) -> int {

        vector<pair<ll, int>> dp(n + 1);

        auto Aliens = [&](int lambda) -> ll {
            for (int i = 1; i <= l - 1; i++) {
                if (sp[i] > lambda) {
                    dp[i] = {sp[i] - lambda, 1};
                } else {
                    dp[i] = {0, 0};
                }
            }
            for (int i = l; i <= n; i++) {
                ll curr = dp[i - l].first + sp[i] - sp[i - l] - lambda;
                if (curr > dp[i - 1].first) {
                    dp[i] = {curr, dp[i - l].second + 1};
                } else {
                    dp[i] = dp[i - 1];
                }
            }
            return dp[n].second;
        };

        int res = numeric_limits<int>::max();
        for (int step = 1 << 30; step; step >>= 1) {
            if (Aliens(res - step) <= k) {
                res -= step;
            }
        }

        Aliens(res);

        return dp[n].first + 1LL * res * k;
    };

    // Solve(lower);

    cout << min(lower[n] - Solve(lower), upper[n] - Solve(upper));

    return 0;
    
}