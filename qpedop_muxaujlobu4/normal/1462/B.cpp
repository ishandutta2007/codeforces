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
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
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
const int mod = 1000000007;
const double eps = 1e-12, pi = acos(-1);
const int maxN = 1001000, maxT = 100010;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    string b = "2020";
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        int ct = 0;
        for (int i = 0; i < min(b.length(), s.length()); ++i) {
            if (s[i] == b[i])++ct;
            else break;
        }
        for (int i = 0; i < min(b.length(), s.length()); ++i) {
            if (s[s.length() - 1 - i] == b[b.length() - 1 - i])++ct;
            else break;
        }
        if (ct >= 4)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}