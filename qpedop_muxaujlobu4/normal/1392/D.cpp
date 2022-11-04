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
const long long mod = 1000000009, mod1 = 1000000007;
const double eps = 1e-13, pi = acos(-1);
const int maxN = 200101;
long long solve(string s) {
    int n = s.length();
    vector<vector<long long>>dp(4, vector<long long>(n, INF));
    if (s[0] == 'R') {
        dp[1][0] = 0;
    }
    else {
        dp[1][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'R') {
            dp[0][i] = dp[2][i - 1] + 1;
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]);
            dp[2][i] = min(dp[1][i - 1], dp[3][i - 1]) + 1;
            dp[3][i] = dp[1][i - 1];
        }
        else {
            dp[0][i] = dp[2][i - 1];
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) +1;
            dp[2][i] = min(dp[1][i - 1], dp[3][i - 1]);
            dp[3][i] = dp[1][i - 1] + 1;
        }
    }
    return min(dp[0].back(), dp[2].back());
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    vector<long long>h;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long ans = INF;
        for (int t = 0; t < 5; ++t) {
            ans = min(ans, solve(s));
            for (int i = n - 2; i >= 0; --i)swap(s[i], s[i + 1]);
        }
        h.push_back(ans);
    }
    for (auto x : h)cout << x << "\n";
    return 0;
}