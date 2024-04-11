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
const long long mod = 1000000007;
long long f(long long m) {
    long long t = 1;
    for (int i = 0; i < 10; ++i) {
        t *= m;
    }
    return t;
}
int arr[10];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long k;
    cin >> k;
    string s = "codeforces";
    long long mn=1;
    while (f(mn) < k)++mn;
    for (int i = 0; i < 10; ++i) {
        arr[i] = mn;
    }
    long long per = f(mn);
    for (int j = 0; j < 10; ++j) {
        if (per / mn * (mn - 1) >= k) {
            per = per / mn * (mn - 1);
            --arr[j];
        }
    }
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < arr[j]; ++i) {
            cout << s[j];
        }
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