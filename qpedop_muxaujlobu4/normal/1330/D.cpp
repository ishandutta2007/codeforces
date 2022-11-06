#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
using namespace std;
//#define double long long;
typedef long double ld;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long INF = 100000000000000;
const int Y = 100000;
long long res, m;
long long Mrec(long long et, long long b) {
    if (b == 0)return 1 % m;
    long long tmp = Mrec(et, b / 2);
    tmp = tmp * tmp % m;
    if (b % 2 == 1)tmp = tmp * et % m;
    return tmp;
}
long long ct[60];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long d;
        cin >> d >> m;
        res = 1;
        long long stpw = 2;
        long long oldpw = 1;
        ct[0] = 1;
        int ii = 0;
        int mx = 0;
        while (true) {
            if (stpw <= d) {
                ct[ii] = stpw - oldpw;
                stpw *= 2;
                oldpw *= 2;
            }
            else {
                ct[ii] = d - oldpw + 1;
                mx = ii;
                break;
            }
            ++ii;
        }
        for (int i = 0; i <= mx; ++i) {
            res = (ct[i] + 1) * res % m;
        }
        res %= m;
        res = (res - 1 + m) % m;
        cout << res % m << "\n";
    }
    return 0;
}
/* Wed Apr 01 2020 21:05:33 GMT+0300 (MSK) */