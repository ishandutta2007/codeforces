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
int arr[100000];
int f[10000];
int l[10000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        bool flag = false;
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> arr[j];
            f[j] = l[j] = -1;
        }
        for (int j = 1; j <= n; ++j) {
            if (f[arr[j]] == -1)f[arr[j]] = j;
            l[arr[j]] = j;
            if (l[arr[j]] - f[arr[j]] >= 2)flag = true;
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */