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
const long long m = 1000000007;
const int Y = 501;
int f(const vector<int>& a, int n, int val) {
    vector<int>t1(2 * n), t2(2 * n);
    for (auto x : a) {
        if (x <= val)++t1[val - x];
        if (x >= val)++t2[x - val];
    }
    int tmp = 0;
    for (int i = 1; i < 2 * n; ++i)tmp += min(t1[i], t2[i]);
    tmp += t1[0] / 2;
    return tmp;
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
        int n, res = 0;
        cin >> n;
        vector<int>a(n);
        for (auto& x : a) {
            cin >> x;
            x *= 2;
        }
        for (int i = 2; i <= 2 * n; ++i) {
            res = max(f(a, n, i), res);
        }
        cout << res << "\n";
    }
    return 0;
}
/*
8 8
7 8 1 1
1 2 1 -1
2 3 1 -1
3 4 1 -1
4 1 1 -1
2 5 1 -10
5 6 1 -10
6 2 1 -10
7 8
*/
//freopen("points.in", "r", stdin);
//freopen("points.out", "w", stdout);

/* Tue Aug 04 2020 00:52:10 GMT+0300 (,  ) */