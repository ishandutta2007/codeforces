#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
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
#include<ctime>
#define double long double
#define int long long
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
const long long INF = 2e18;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1010;
void panic() {
    cout << -1;
    exit(0);
}

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y, n;
        int ans = INF;
        cin >> a >> b >> x >> y >> n;
        if (abs(a - x) + abs(b - y) <= n) {
            cout << x * y << "\n";
            continue;
        }
        int tmp = abs(a - x);
        if (tmp <= n) {
            int tx = x;
            int tn = n - tmp;
            ans = min(ans, tx * (b - tn));
        }
        else ans = min(ans, (a - n) * b);
        swap(a, b);
        swap(x, y);
        tmp = abs(a - x);
        if (tmp <= n) {
            int tx = x;
            int tn = n - tmp;
            ans = min(ans, tx * (b - tn));
        }
        else ans = min(ans, (a - n) * b);
        cout << ans << "\n";
    }
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/