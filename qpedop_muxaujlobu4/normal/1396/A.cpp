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
    vector<long long>a(n);
    for (auto& x : a)cin >> x;
    if (n == 1) {
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; ++i) {
        long long tmp = (a[i] % n + n) % n;
        tmp = n - tmp;
        tmp = (long long)(n - tmp) * (n - 1);
        a[i] += tmp;
        cout << tmp << " ";
    }
    cout << "\n";
    cout << 2 << " " << n << "\n";
    for (int i = 1; i < n; ++i) {
        long long tmp = (a[i] % n + n) % n;
        tmp = n - tmp;
        tmp = (long long)(n - tmp) * (n - 1);
        a[i] += tmp;
        cout << tmp << " ";
    }
    cout << "\n";
    cout << 1 << " " << n << "\n";
    for (auto x : a)cout << -x << " ";
    cout << "\n";
    return 0;
}