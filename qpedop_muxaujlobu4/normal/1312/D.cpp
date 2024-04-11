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
#include<ctime>
#include<random>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>

void boostIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
const int Y = 200100;
const long long m = 998244353;
long long f[Y];
long long g[Y];
long long p2[Y];
template<typename T> T getint() {
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
long long pw(long long et, int b = m - 2) {
    if (b == 0)return 1;
    long long tmp = pw(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
long long c(long long n, long long k) {
    return f[n] * g[k] % m * g[n - k] % m;
}
int main()
{
    boostIO();
    int n, mm;
    cin >> n >> mm;
    long long ans = 0;
    f[0] = 1;
    g[0] = 1;
    p2[0] = 1;
    for (long long i = 1; i <= mm; ++i) {
        f[i] = f[i - 1] * i % m;
        g[i] = pw(f[i]);
        p2[i] = p2[i - 1] * 2 % m;
    }
    if (n == 2) {
        cout << 0;
        return 0;
    }
    for (int i = n - 1; i <= mm; ++i) {
       // cout << i - 1 << " " << n - 2 << " " << c(i - 1, n - 2) << endl;
        ans = (ans + c(i - 1, n - 2)) % m;
    }

    ans = (ans * p2[n - 3]) % m;
    ans = (ans * (n - 2)) % m;
    cout << ans;
    return 0;
}