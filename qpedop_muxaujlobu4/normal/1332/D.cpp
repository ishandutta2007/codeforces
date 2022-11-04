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
const int Y = 1000;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
int arr[3][3];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    cout.precision(15);
    int k;
    cin >> k;
    const int tt = 262143;
    if (k == 0) {
        cout << 1 << " " << 1 << endl;
        cout << 1;
        return 0;
    }
    else {
        cout << 3 << " " << 3 << endl;
        arr[0][0] = arr[1][1] = tt;
        arr[1][0] = k;
        arr[1][2] = arr[2][1] = arr[2][2] = k;
        arr[0][1] = tt ^ k;
        arr[0][2] = arr[2][0] = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */