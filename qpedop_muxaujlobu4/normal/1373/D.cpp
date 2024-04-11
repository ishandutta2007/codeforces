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
using namespace std;
int gcd(int i, int j) {
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
const long long INF = 10000000;
const int Y = 200100;
const long long m = 1000000007;
long long a[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long s = 0;
        vector<long long>a(n);
        set<long long>b1 = { 0 };
        set<long long>b2 = { 0 };
        long long w1 = 0, w2 = 0;
        long long df = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i % 2 == 0) {
                s += a[i];
                if (i != 0) {
                    w2 += a[i - 1] - a[i];
                    b2.insert(w2);
                    long long t2 = w2 - (*b2.begin());
                    df = max(df, t2);
                }
            }
            else {
                w1 += a[i] - a[i - 1];
                b1.insert(w1);
                long long t1 = w1 - (*b1.begin());
                df = max(df, t1);
            }
        }
        cout << s + df << endl;
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */