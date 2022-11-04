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
const long long INF = 1e18;
//const int mod = 1000000007;
int mod;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int sz = 1;
long long to_push[maxN << 2];
long long tree[maxN << 2];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tst = 0; tst < t; ++tst) {
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto& x : a)cin >> x;
        int j = a[0];
        a[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j1 = max(0, min(j, a[i] - a[i - 1]));
            a[i] -= j1;
            j = j1;
        }
        bool c = true;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] > a[i + 1])c = false;
        }
        if (c)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}