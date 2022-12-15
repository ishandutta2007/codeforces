#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define mod 1000000007
using namespace std;

long long r, g, dp[200005][2], h;

int main() {
    cin >> r >> g;
    if (r > g) swap(r, g);
    for (long long i = 1; i < 1000; i++) {
        if (i * (i + 1) / 2 <= r + g) h = i;
        else break;
    }
    long long cur = 1;
    dp[0][1] = dp[1][1] = 1;
    for (long long i = 2; i <= h; i++) {
        for (long long j = 0; j <= r; j++) dp[j][i % 2] = 0;
        for (long long last = 0; last + i <= r && last <= cur; last++) 
            dp[last + i][i % 2] = dp[last][(i + 1) % 2];
        for (long long last = 0; last <= cur && last <= r; last++) {
            dp[last][i % 2] += dp[last][(i + 1) % 2];
            dp[last][i % 2] %= mod;
        }
        cur += i;
    }
    long long ans = 0;
    for (long long i = 0; i <= r; i++) {
        if (i + g >= h * (h + 1) / 2) ans += dp[i][h % 2];
        ans %= mod;
    }
    cout << ans;
}