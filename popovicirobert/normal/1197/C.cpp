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
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i] = min(dp[j] + arr[i] - arr[j + 1] + lambda)

    vector<pair<ll, int>> dp(n + 1);

    auto Aliens = [&](int lambda) {
        int id = 0;
        for (int i = 1; i <= n; i++) {
            ll curr = dp[id].first + arr[i] - arr[id + 1] + lambda;
            dp[i] = {curr, dp[id].second + 1};

            if (i < n && dp[i].first - arr[i + 1] < dp[id].first - arr[id + 1]) {
                id = i;
            }
        }
        return dp[n].second;
    };

    int res = -1;
    for (int step = 1 << 30; step; step >>= 1) {
        if (Aliens(res + step) > k) {
            res += step;
        }
    }

    res++;
    Aliens(res);

    cout << dp[n].first - 1LL * res * k;
    
    return 0;
    
}