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
#include<bitset>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
const int INF = 1000000000;
const int Y = 1000;
int arr[Y];
int dp1[Y];
int dp2[Y];
int main()
{
    srand(10241274216);
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int s1 = 0;
    int s2 = 0;
    int mn = 1000;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            s2 += tmp;
        }
        else {
            mn = min(mn, tmp);
            s1 += tmp;
        }
    }
    if (mn == 1000) {
        cout << 0;
    }
    else {
        if (s1 % 2 == 0)s1 -= mn;
        cout << s2 + s1;
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);