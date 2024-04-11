#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const old PI = acos(-1.0);

const int N = 1010;

char a[N][N];
int used[N][N];
ll s[N];
int ans[N];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> s[i];
    }
    int cnt = n * m;
    queue< pair<int, int> > q[10];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] >= '1' && a[i][j] <= '9') {
                q[a[i][j] - '0'].push({ i, j });
                used[i][j] = 1;
            }
            if (a[i][j] != '.') {
                --cnt;
            }
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                a[i][j] = '#';
            }
        }
    }
    int iter = 0;
    bool f = true;
    while (cnt && f) {
        ++iter;
        f = false;
        for (int i = 1; i <= p; ++i) {
            while (!q[i].empty() && used[q[i].front().first][q[i].front().second] <= s[i] * iter) {
                f = true;
                auto v = q[i].front();
                q[i].pop();
                ++ans[i];
                for (int d = 0; d < 4; ++d) {
                    int x = v.first + dx[d];
                    int y = v.second + dy[d];
                    if (a[x][y] != '#' && !used[x][y]) {
                        used[x][y] = used[v.first][v.second] + 1;
                        q[i].push({ x, y });
                        --cnt;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= p; ++i) {
        int t = 0;
        if (!q[i].empty()) {
            t = q[i].size();
        }
        cout << ans[i] + t << ' ';
    }
    return 0;
}