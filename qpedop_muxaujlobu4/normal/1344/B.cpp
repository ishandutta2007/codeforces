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
#include<ctime>
#include<random>
using namespace std;
const unsigned long long INF = 1e17;
const int INFi = 2e8;
const int Y = 200100;
const long long m = 998244353;
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
long long PW(long long et, long long b) {
    if (b == 0)return 1;
    long long tmp = PW(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
int f[1001000];
char W[1001][1001];
int p1[1001][1001];
int p2[1001][1001];
int c1[1001][1001];
int c2[1001][1001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        W[i][0] = '.';
        int c = 0;
        for (int j = 1; j <= m; ++j) {
            cin >> W[i][j];
            if (W[i][j] == '#' && W[i][j - 1] == '.')++c;
        }
        if (c > 1) {
            cout << -1;
            return 0;
        }
    }
    for (int j = 0; j <= m; ++j)W[0][j] = '.';
    for (int j = 1; j <= m; ++j) {
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if (W[i][j] == '#' && W[i - 1][j] == '.')++c;
        }
        if (c > 1) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (W[i][j] == '#') {
                p1[i][j] = p1[i][j - 1] + 1;
            }
            else {
                p1[i][j] = p1[i][j - 1];
            }
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (W[i][j] == '#') {
                p2[i][j] = p2[i - 1][j] + 1;
            }
            else {
                p2[i][j] = p2[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (W[i][j] == '#' || (p1[i][m] == 0 && p2[n][j] == 0)) {
                c1[i][j] = c1[i][j - 1] + 1;
                c2[i][j] = c2[i - 1][j] + 1;
            }
            else {
                c1[i][j] = c1[i][j - 1];
                c2[i][j] = c2[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c1[i][m] == 0) {
            cout << -1;
            return 0;
        }
    }
    for (int j = 1; j <= m; ++j) {
        if (c2[n][j] == 0) {
            cout << -1;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (p1[i][m] == 0)continue;
        if (p1[i - 1][m] == 0) {
            ++ans;
            continue;
        }
        int y1 = 0, y2 = m;
        int b1 = 0, b2 = m;
        while (W[i][y1] == '.')++y1;
        while (W[i][y2] == '.')--y2;
        while (W[i - 1][b1] == '.')++b1;
        while (W[i - 1][b2] == '.')--b2;
        if (!(max(b1, y1) <= min(b2, y2))) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}