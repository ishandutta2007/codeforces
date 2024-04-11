#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int fr[10];
ll dp[10][20];
ll comb[20][20];

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j;
    ll n;
    ios::sync_with_stdio(false);
    for(i = 0; i < 20; i++) {
        comb[i][0] = 1;
        for(j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    cin >> n;
    while(n > 0) {
        fr[n % 10]++;
        n /= 10;
    }
    int tot = 0;
    for(i = 0; i < 10; i++) {
        tot += fr[i];
    }
    ll ans = 0;
    for(int len = 1; len <= tot; len++) {
        memset(dp, 0, sizeof(dp));
        for(j = (fr[0] > 0); j <= len && j <= fr[0]; j++) {
            dp[0][j] = comb[len - 1][j];
        }
        for(i = 1; i <= 9; i++) {
            for(j = 0; j <= len; j++) {
                for(int cur = (fr[i] > 0); cur <= len - j && cur <= fr[i]; cur++) {
                    dp[i][j + cur] += dp[i - 1][j] * comb[len - j][cur];
                }
            }
        }
        ans += dp[9][len];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}