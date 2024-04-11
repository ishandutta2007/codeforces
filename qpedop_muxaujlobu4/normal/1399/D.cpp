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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>a(n);
        int b = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')++b;
            else --b;
            if (s[i] == '1') {
                if (b > 0) {
                    mx = max(b, mx);
                    a[i] = b;
                }
            }
            else {
                if (b >= 0) {
                    a[i] = b + 1;
                }
            }
        }
        int mx1 = 0;
        b = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')++b;
            else --b;
            if (s[i] == '0') {
                if (b > 0) {
                    mx1 = max(mx1, b);
                    a[i] = b + mx;
                }
            }
            else {
                if (b >= 0) {
                    a[i] = b + 1 + mx;
                }
            }
        }
        cout << mx + mx1 << "\n";
        for (auto x : a)cout << x << " ";
        cout << "\n";

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