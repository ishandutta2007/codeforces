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
using namespace std;
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
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
const long long INF = 100000000000000;
const int Y = 100000;
long long arr[Y + 1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, x, y, x1, x2, y1, y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x == x1 && x == x2 && (a!=0 || b!= 0 )) {
            cout << "NO\n";
            continue;
        }
        if (y == y1 && y == y2 && ((c != 0) || (d != 0))) {
            cout << "NO\n";
            continue;
        }
        b -= a;
        d -= c;
        if (x1 <= b + x && b + x <= x2 && y1 <= d + y && d + y <= y2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */