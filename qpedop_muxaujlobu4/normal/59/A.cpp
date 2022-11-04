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
const int Y = 100000;
int main()
{
    srand(10241274216);
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto x1 : s) {
        if (islower(x1))++x;
        else ++y;
    }
    if (x >= y) {
        for (auto& x1 : s) {
            if (isupper(x1)) {
                x1 = x1 - 'A' + 'a';
            }
        }
    }
    else {
        for (auto& x1 : s) {
            if (islower(x1))x1 = x1 - 'a' + 'A';
        }
    }
    cout << s;
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);