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
using ul = unsigned long long;
using ld = long double;

int n, m;

int fs(int lx, int ly, int rx, int ry, vector<vector<int>> &ps) {
    return ps[rx][ry] - ps[rx][ly] - ps[lx][ry] + ps[lx][ly];
}

int ck(int x, int y, int d, vector<vector<int>> &ps) {
    return x >= d && x + d <= n && y >= d && y + d <= m && fs(x - d, y - d, x + d + 1, y + d + 1, ps) == (2 * d + 1) * (2 * d + 1);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2)), ps(n + 2, vector<int>(m + 2)), ns;
    string s;
    rep(i, n) {
        cin >> s;
        rep(j, m)
            if (s[j] == 'X')
                a[i + 1][j + 1] = 1;
    }
    rep(i, n + 1)
        rep(j, m + 1)
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + a[i][j];
    int l = 0, r = min(n, m) + 1, md;
    while (r - l > 1) {
        md = (l + r) / 2;
        ns.assign(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (ck(i, j, md, ps)) {
                    ns[i][j] = 1;
                }
        rep(i, n + 1)
            rep(j, m + 1)
                ns[i + 1][j + 1] += ns[i][j + 1] + ns[i + 1][j] - ns[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] && fs(max(i - md - 1, 0), max(j - md - 1, 0), min(i + md, n + 1), min(j + md, m + 1), ns) == 0) {
                    r = md;
                }
        if (r != md)
            l = md;
    }
    cout << l << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << (ck(i, j, l, ps) ? 'X' : '.');
        cout << '\n';
    }
}