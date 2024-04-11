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
using namespace std;
int gcd(int i, int j) {
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
long long INF = 1e17;
const long long m = 1000000007;
const int Y = 510;
int dp[Y][Y];
int a[Y];
int n;
int ans[Y];
void Mrec(int l, int r) {
    if (dp[l][r] != -1)return;
    dp[l][r] = -2;
    for (int j = l; j < r; ++j) {
        Mrec(l, j);
        Mrec(j + 1, r);
        if (dp[l][j] >= 0 && dp[l][j] == dp[j + 1][r]) {
            dp[l][r] = dp[l][j] + 1;
            return;
        }
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= n; ++j) {
            if (j == i)dp[i][j] = a[i];
            else dp[i][j] = -1;
        }
        ans[i] = i;
    }
    Mrec(1, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (dp[j][i] >= 0)ans[i] = min(ans[i], ans[j - 1] + 1);
        }
    }
    cout << ans[n] << endl;
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */