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
long long p[Y];
long long in[Y];
long long BP(long long et, long long b) {
    if (b == 0)return 1;
    long long tmp = BP(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = tmp * et % m;
    return tmp;
}
long long c(int n, int k) {
    return p[n] * in[k] % m * in[n - k] % m;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    p[0] = in[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * i % m;
        in[i] = BP(p[i], m - 2);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + c(n - 1, i - 1)) % m;
    }
    cout << (p[n] - ans + m) % m;
    return 0;
}