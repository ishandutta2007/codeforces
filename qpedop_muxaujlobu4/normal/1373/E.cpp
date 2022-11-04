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
const long long INF = 1e17;
const long long m = 1000000007;
bool change(string a, string b) {
    if (a == "-1")return true;
    if (a.length() > b.length())return true;
    if (b.length() > a.length())return false;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] > b[i])return true;
        if (b[i] > a[i])return false;
    }
    return false;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ++k;
        string ans = "-1";
        for (int stW = 0; stW < 10; ++stW) {
            if (stW == 9) {
                int yu = 0;
            }
            int sm = 0, k1 = 0;
            for (int j = 0; j < k; ++j) {
                sm += (stW + j) % 10;
                if (stW + j < 10)++k1;
                else {
                    ++sm;
                }
            }
            for (int cl9 = 0; cl9 < 20; ++cl9) {
                int tmp = sm + k1 * cl9 * 9;
                if (tmp > n)break;
                int tmp1 = n - tmp;
                if (tmp1 % k != 0)continue;
                tmp1 /= k;
                string ca = "";
                if (tmp1 >= 8) {
                    tmp1 -= 8;
                    ca.push_back('8');
                }
                while (tmp1) {
                    if (tmp1 >= 9) {
                        tmp1 -= 9;
                        ca.push_back('9');
                    }
                    else {
                        ca.push_back('0' + tmp1);
                        tmp1 = 0;
                    }
                }
                reverse(ca.begin(), ca.end());
                for (int hh = 0; hh < cl9; ++hh)ca.push_back('9');
                ca.push_back('0' + stW);
                if (change(ans, ca))ans = ca;
            }
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