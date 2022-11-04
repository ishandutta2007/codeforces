#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
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
const double INF = 1e17;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    int t;
    cin >> t;
    while (t--) {
        int q, n;
        cin >> n >> q;
        vector<vector<long long>>dp(2, vector<long long>(n + 1, -INF));
        dp[1][0] = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            dp[0][i + 1] = max(dp[0][i], dp[1][i] + tmp);
            dp[1][i + 1] = max(dp[1][i], dp[0][i] - tmp);
        }
        cout << max(dp[0].back(), dp[1].back()) << endl;
    }
    return 0;
}