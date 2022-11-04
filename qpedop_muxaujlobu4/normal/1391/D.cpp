#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int short
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 2e17;
const long long m = 1000000007;
const int Y = 1000101;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n, m;
    cin >> n >> m;
    if (n > m)swap(n, m);
    vector<string>mt(n);
    for (int i = 0; i < n; ++i)cin >> mt[i];
    if (min(n, m) >= 4) {
        cout << -1;
        return 0;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        vector<vector<int>>dp(4, vector<int>(m));
        int tmp = 0;
        if (mt[0][0] == '1')tmp |= 1;
        if (mt[1][0] == '1')tmp |= 2;
        for (int j = 0; j < 4; ++j) {
            int ct = 0;
            for (int k = 0; k < 2; ++k) {
                if ((tmp & (1 << k)) != (j & (1 << k)))++ct;
            }
            dp[j][0] = ct;
        }
        for (int j = 1; j < m; ++j) {
            int tmp = 0;
            if (mt[0][j] == '1')tmp |= 1;
            if (mt[1][j] == '1')tmp |= 2;
            for (int j1 = 0; j1 < 4; ++j1) {
                int ct = 0;
                for (int k = 0; k < 2; ++k) {
                    if ((tmp & (1 << k)) != (j1 & (1 << k)))++ct;
                }
                dp[j1][j] = ct;
            }
            dp[3][j] += min(dp[2][j - 1], dp[1][j - 1]);
            dp[0][j] += min(dp[2][j - 1], dp[1][j - 1]);
            dp[1][j] += min(dp[0][j - 1], dp[3][j - 1]);
            dp[2][j] += min(dp[0][j - 1], dp[3][j - 1]);
        }
        int ans = dp[0][m - 1];
        for (int i = 1; i < 4; ++i)ans = min(ans, dp[i][m - 1]);
        cout << ans;
        return 0;
    }
    vector<vector<int>>dp(8, vector<int>(m));
    int tmp = 0;
    if (mt[0][0] == '1')tmp |= 1;
    if (mt[1][0] == '1')tmp |= 2;
    if (mt[2][0] == '1')tmp |= 4;
    for (int j1 = 0; j1 < 8; ++j1) {
        int ct = 0;
        for (int k = 0; k < 3; ++k) {
            if ((tmp & (1 << k)) != (j1 & (1 << k)))++ct;
        }
        dp[j1][0] = ct;
    }
    for (int j = 1; j < m; ++j) {
        int tmp = 0;
        if (mt[0][j] == '1')tmp |= 1;
        if (mt[1][j] == '1')tmp |= 2;
        if (mt[2][j] == '1')tmp |= 4;
        for (int j1 = 0; j1 < 8; ++j1) {
            int ct = 0;
            for (int k = 0; k < 3; ++k) {
                if ((tmp & (1 << k)) != (j1 & (1 << k)))++ct;
            }
            dp[j1][j] = ct;
        }
        dp[7][j] += min(dp[5][j - 1], dp[2][j - 1]);
        dp[0][j] += min(dp[5][j - 1], dp[2][j - 1]);
        dp[1][j] += min(dp[3][j - 1], dp[4][j - 1]);
        dp[2][j] += min(dp[7][j - 1], dp[0][j - 1]);
        dp[5][j] += min(dp[7][j - 1], dp[0][j - 1]);
        dp[3][j] += min(dp[1][j - 1], dp[6][j - 1]);
        dp[4][j] += min(dp[6][j - 1], dp[1][j - 1]);
        dp[6][j] += min(dp[4][j - 1], dp[3][j - 1]);
    }
    int ans = dp[0][m - 1];
    for (int i = 1; i < 8; ++i)ans = min(ans, dp[i][m - 1]);
    cout << ans;
    return 0;
}