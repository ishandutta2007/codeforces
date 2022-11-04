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
#define double long double
#define int long long
using namespace std;
long long gcd(long long i, long long j) {
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
const long long INF = 8e17;
//const long long m = 1000000007;
const int Y = 200100;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    //freopen("flow.in", "r", stdin);
   // freopen("flow.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        vector<int>a(3);
        for (auto& x : a)cin >> x;
        sort(a.begin(), a.end());
        if (a[1] == a[2]) {
            cout << "YES\n";
            cout << a[2] << " " << a[0] << " " << 1 << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
/*
8 8
7 8 1 1
1 2 1 -1
2 3 1 -1
3 4 1 -1
4 1 1 -1
2 5 1 -10
5 6 1 -10
6 2 1 -10
7 8
*/
/* Fri Jul 10 2020 08:35:42 GMT+0300 (,  ) */

/* Sat Jul 11 2020 18:41:06 GMT+0300 (,  ) */

/* Sat Jul 11 2020 19:52:11 GMT+0300 (,  ) */