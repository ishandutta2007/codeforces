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
const int Y = 1000;
bool vis[26];
int main()
{
    srand(10241274216);
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int len = s.length();
    for (auto x : s) {
        if (x != '?') {
            vis[x - 'a'] = true;
        }
    }
    int add = 0;
    for (int i = 0; i < k; ++i) {
        if (!vis[i])++add;
    }
    int i, j;
    if (len % 2 == 0) {
        i = len / 2 - 1;
        j = i + 1;
    }
    else {
        i = j = len / 2;
    }
    for (; i >= 0 ; --i, ++j) {
        if (s[i] == s[j]) {
            if (s[i] == '?') {
                if (add == 0) {
                    s[i] = s[j] = 'a';
                }
                else {
                    --add;
                    for (int ii = k - 1; ii >= 0; --ii) {
                        if (!vis[ii]) {
                            vis[ii] = true;
                            s[i] = s[j] = 'a' + ii;
                            break;
                        }
                    }
                }
            }
        }
        else {
            if (s[i] == '?') {
                s[i] = s[j];
            }
            else {
                if (s[j] == '?') {
                    s[j] = s[i];
                }
                else {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }
    if (add > 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << s;
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */

/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */

    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);