#pragma comment(linker, "/STACK:9759095000")
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
const long long INF = 1e9;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1070100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
long long bin_pow(int b, long long et) {
    if (b == 0)return 1;
    long long tmp = bin_pow(b / 2, et);
    tmp = (tmp * tmp) % mod;
    if (b % 2 == 1)tmp = (tmp * et) % mod;
    return tmp;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long>dp(n + 1);
    dp[0] = 1;
    long long s0 = 1;
    long long s1 = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            dp[i] = s1;
            s0 = (s0 + dp[i]) % mod;
        }
        else {
            dp[i] = s0;
            s1 = (s1 + dp[i]) % mod;
        }
    }



    cout << dp[n] * bin_pow(mod - 2, bin_pow(n, 2)) % mod << endl;
    return 0;
}