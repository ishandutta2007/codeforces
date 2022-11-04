#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
long long arr[2001];
long long dp[2001][2001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    long long ans = 0;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < h; ++j)dp[i][j] = -1;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            if (dp[i][j] == -1)continue;
            dp[i + 1][(j + arr[i]) % h]=max(dp[i + 1][(j + arr[i]) % h], dp[i][j]);
            dp[i + 1][(j + arr[i] - 1) % h] = max(dp[i + 1][(j + arr[i] - 1) % h], dp[i][j]);
        }
        for (int j = l; j <= r; ++j) {
            if (dp[i + 1][j] != -1)dp[i + 1][j]++;
        }
    }
    for (int i = 0; i < h; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */