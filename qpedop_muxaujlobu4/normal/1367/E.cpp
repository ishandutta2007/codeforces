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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        vector<int>bk(26);
        cin >> s;
        for (auto x : s)++bk[x - 'a'];
        int ans = 0;
        for (auto x : bk)ans = max(x, ans);
        for (int i = ans + 1; i <= n; ++i) {
            int tmp = k % i;
            if (tmp == 0) {
                ans = i;
                continue;
            }
            int ct = i / gcd(max(i, tmp), min(i, tmp));
            int sm = 0;
            for (int j = 0; j < 26; ++j) {
                sm += bk[j] / ct;
            }
            if (sm * ct >= i)ans = i;
        }
        cout << ans << endl;
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