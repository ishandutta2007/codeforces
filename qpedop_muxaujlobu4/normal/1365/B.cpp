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
const long long INF = 100000000;
const int Y = 1000100;
//const long long m = 1000000007;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        bool res = true;
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (auto& x : a)cin >> x;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            if (b[i] == 0)++c1;
            else ++c2;
        }
        if (c1 == 0 || c2 == 0) {
            for (int i = 1; i < n; ++i) {
                if (a[i - 1] > a[i])res = false;
            }
        }
        if (res)cout << "Yes\n";
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