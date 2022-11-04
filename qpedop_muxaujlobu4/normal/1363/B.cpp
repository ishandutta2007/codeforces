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
        string s;
        cin >> s;
        int n = s.size();
        vector<int>p(s.size() + 1);
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1')p[i + 1] = p[i] + 1;
            else p[i + 1] = p[i];
        }
        int ans = s.size();
        for (int i = 1; i <= n; ++i) {
            int c1 = p[i] + n - i - (p[n] - p[i]);
            ans = min(ans, c1);
            int c2 = i - p[i] + p[n] - p[i];
            ans = min(ans, c2);
        }
        cout << ans << "\n";
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