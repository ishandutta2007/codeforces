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
const double e = 0.0000005;
const double pi = 3.14159265359;
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
int main()
{
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ++ii) {
        int x;
        cin >> x;
        cout << 1 << " " << x - 1 << "\n";
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);