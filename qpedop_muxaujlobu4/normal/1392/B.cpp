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
const int maxN = 200101;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long>a(n);
        for (auto& x : a)cin >> x;
        if (k != 1)k = 2 + k % 2;
        for (int k1 = 0; k1 < k; ++k1) {
            long long mx = a[0];
            for (auto x : a)mx = max(mx, x);
            for (auto& x : a)x = mx - x;
        }
        for (auto x : a)cout << x << " ";
        cout << "\n";
    }
    return 0;
}