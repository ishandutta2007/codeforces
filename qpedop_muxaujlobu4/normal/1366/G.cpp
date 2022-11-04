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
const long long INF = 1e7;
const int Y = 10010;
const long long m = 998244353;
int dp[Y][Y];
int ans = INF;
string s, t;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int r = -1;
        int bal = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '.')--bal;
            else ++bal;
            if (bal < 0)break;
            if (bal == 0) {
                r = j + 1;
                break;
            }
        }
        if (r != -1) {
            for (int j = 0; j <= m; ++j) {
                dp[r][j] = min(dp[r][j], dp[i][j]);
            }
        }
        if (s[i] != '.') {
            for (int j = 0; j < m; ++j) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                }
            }
        }
        else {
            for (int j = 1; j <= m; ++j) {
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
            }
        }
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }
    }


    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i][m] + n - i);
    }
    cout << ans << endl;
    return 0;
}