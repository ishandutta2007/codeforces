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
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
long long solve(vector<int>a, vector<int>b) {
    long long res = 0;
    res += min(a[0], b[0]);
    b[0] -= res;
    for (int j = 1; j < 3; ++j) {
        int tt = min(a[j], b[j] + b[j - 1]);
        res += tt;
        tt -= b[j - 1];
        b[j] -= max(0, tt);
    }
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
  //  file_inc();
    int n;
    cin >> n;
    vector<int>a(3), b(3);
    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;
    long long ans2 = 0;
    for (int j = 0; j < 3; ++j)ans2 += min(a[j], b[(j + 1) % 3]);
    long long ans1 = INF;
    for (int t = 0; t < 3; ++t) {
        ans1 = min(ans1, n - solve(a, b));
        for (int j = 1; j >= 0; --j) {
            swap(a[j], a[j + 1]);
            swap(b[j], b[j + 1]);
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}