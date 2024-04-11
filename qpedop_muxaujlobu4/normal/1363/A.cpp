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
//#define int long long
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
const long long INF = 1e17;
const int Y = 200100;

//const long long m = 1000000007;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0)++c2;
            else ++c1;
        }
        if (c1 % 2 == 0)--c1;
        if (c2 == 0 && x % 2 == 0) {
            cout << "No\n";
            continue;
        }
        if (c1 != -1 && c2 + c1 >= x)cout << "Yes\n";
        else cout << "No\n";
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