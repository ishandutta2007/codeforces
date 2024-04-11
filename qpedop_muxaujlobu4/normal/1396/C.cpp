#pragma comment(linker, "/STACK:2759095000")
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
const long long INF = 5e18;
const long long mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 200100;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(1);
    int n;
    cin >> n;
    long long ans = INF, r1, r2, r3, d;
    cin >> r1 >> r2 >> r3 >> d;
    vector<long long>a(n);
    for (auto& x : a)cin >> x;
    vector<vector<long long>>dp(2, vector<long long>(n, INF));
    dp[0][0] = a[0] * r1 + r3;
    dp[1][0] = min(r2, r1 * (a[0] + 1));
    for (int i = 1; i < n; ++i) {
        dp[0][i] = min(dp[0][i - 1] + d + r1 * a[i] + r3, min(dp[0][i - 1], dp[1][i - 1] + r1) + 3 * d + min(r1 * a[i] + r3, min(r1 * (a[i] + 2), r2 + r1)));
        dp[1][i] = dp[0][i - 1] + min(r1 * (a[i] + 1), r2) + d;
    }
    ans = dp[0].back();
    long long tmp = r1 * a.back() + r3 + 2 * d;
    for (int i = n - 2; i >= 0; --i) {
        tmp += 2 * d + min(r1 * a[i] + r3, min(r2 + r1, r1 * (a[i] + 2)));
        long long tt = 0;
        if (i)tt = dp[0][i - 1] - d;
        else tt = -2 * d;
        ans = min(ans, tmp + tt);
    }
    cout << ans;
    return 0;
}