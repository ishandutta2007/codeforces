#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 52;
char a[N][N];
int dp[N][N][N][N], ps[N][N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        rep(j, n)
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + (a[i][j] == '#' ? 1 : 0);
    }
    for (int dx = 1; dx <= n; dx++)
        for (int dy = 1; dy <= n; dy++)
            for (int lx = 0, rx = dx; rx <= n; lx++, rx++)
                for (int ly = 0, ry = dy; ry <= n; ly++, ry++) {
                    if (ps[rx][ry] - ps[lx][ry] - ps[rx][ly] + ps[lx][ly] == 0)
                        continue;
                    dp[lx][ly][rx][ry] = max(rx - lx, ry - ly);
                    for (int mx = lx + 1; mx < rx; mx++)
                        dp[lx][ly][rx][ry] = min(dp[lx][ly][rx][ry], dp[lx][ly][mx][ry] + dp[mx][ly][rx][ry]);
                    for (int my = ly + 1; my < ry; my++)
                        dp[lx][ly][rx][ry] = min(dp[lx][ly][rx][ry], dp[lx][ly][rx][my] + dp[lx][my][rx][ry]);
                }
    cout << dp[0][0][n][n];
}