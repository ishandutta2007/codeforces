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
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
  //  file_inc();
    int n;
    cin >> n;
    vector<vector<long long>> ct(4, vector<long long>(n + 1, 0));
    ct[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        char t;
        cin >> t;
        if (t == '?' || t == 'a') {
            int j = 1;
            for (int y = 0; y < 4; ++y)
                if (y != j)ct[y][i + 1] = (ct[y][i + 1] + ct[y][i]) % mod;
            long long sm = 0;
            for (int y = 0; y < 2; ++y)sm += ct[y][i];
            ct[j][i + 1] = (ct[j][i + 1] + sm) % mod;
        }
        if (t == '?' || t == 'b') {
            int j = 2;
            for (int y = 0; y < 4; ++y)
                if (y != j)ct[y][i + 1] = (ct[y][i + 1] + ct[y][i]) % mod;
            long long sm = 0;
            for (int y = 1; y < 3; ++y)sm += ct[y][i];
            ct[j][i + 1] = (ct[j][i + 1] + sm) % mod;
        }
        if (t == '?' || t == 'c') {
            int j = 3;
            for (int y = 0; y < 4; ++y)
                if (y != j)ct[y][i + 1] = (ct[y][i + 1] + ct[y][i]) % mod;
            long long sm = 0;
            for (int y = 2; y < 4; ++y)sm += ct[y][i];
            ct[j][i + 1] = (ct[j][i + 1] + sm) % mod;
        }
    }
    cout << ct[3][n];
    return 0;
}