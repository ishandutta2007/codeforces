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
const int maxN = 1000101;
long long h[maxN];
long long arif(long long l, long long r) {
    return (r - l + 1) * (r + l) / 2;
}
int n;
long long pl[maxN];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    n = getint<int>();
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        h[i] = getint<long long>();
        s += h[i];
    }
    long long b = 0, e = h[n - 1] + 1;
    while (b + 1 != e) {
        long long m = (b + e) / 2;
        if (arif(m - n + 1, m) <= s)b = m;
        else e = m;
    }
    s -= b;
    h[n - 1] = b;
    for (int i = n - 2; i >= 0; --i) {
        long long tmp;
        if (arif(h[i + 1] - i, h[i + 1]) <= s)tmp = h[i + 1];
        else tmp = h[i + 1] - 1;
        s -= tmp;
        h[i] = tmp;
    }
    for (int i = 0; i < n; ++i)cout << h[i] << " ";
    return 0;
}