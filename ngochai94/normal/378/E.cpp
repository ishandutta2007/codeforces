#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;

int n, lis[111], dp[1<<22], team[22], m;
char action[22];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }
    sort(lis, lis + n);
    for (int i = 0; i < n / 2; i++) {
        swap(lis[i], lis[n - 1 - i]);
    }
    cin >> m;
    for (int i = m; i > 0; i--) {
        cin >> action[i] >> team[i];
    }
    for (int mask = 1; mask < (1 << m); mask++) {
        int cnt = __builtin_popcount(mask);
        if (team[cnt] == 1) {
            dp[mask] = -mod;
            for (int i = 0; i < m; i++) if ((1 << i) & mask) {
                if (action[cnt] == 'p') dp[mask] = max(dp[mask], lis[i] + dp[mask ^ (1 << i)]);
                else dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
            }
        } else {
            dp[mask] = mod;
            for (int i = 0; i < m; i++) if ((1 << i) & mask) {
                if (action[cnt] == 'p') dp[mask] = min(dp[mask], -lis[i] + dp[mask ^ (1 << i)]);
                else dp[mask] = min(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }
    cout << dp[(1 << m) - 1];
}