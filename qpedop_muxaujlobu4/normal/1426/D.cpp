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
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
long long f(long long ct, long long n) {
    long long res = ct;
    long long vl = 1 + ct;
    res += (n + vl - 1) / vl;
    return res - 1;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
 //   file_inc();
    int n;
    cin >> n;
    vector<long long>a(n);
    for (auto& x : a)cin >> x;
    int ans = 0;
    set<long long>s = { 0 };
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += a[i];
        if (s.count(sm)) {
            ++ans;
            s.clear();
            sm = a[i];
            s.insert(0);
            s.insert(sm);
        }
        else {
            s.insert(sm);
        }
    }
    cout << ans;
    return 0;
}