#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7, N = 25e4 + 7, K = 1e1 + 2;
vector <pair <int, int>> g[N];
int n, m, k, dp[N][K];
int get(int i, int j) {
    return i * m + j;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int x; cin >> x;
            g[get(i, j)].push_back({ get(i, j + 1), x });
            g[get(i, j + 1)].push_back({ get(i, j), x });
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            g[get(i, j)].push_back({ get(i + 1, j), x });
            g[get(i + 1, j)].push_back({ get(i, j), x });
        }
    }
    if (k & 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << "-1 ";
            cout << '\n';
        }
        return 0;
    }
    for (int l = 0; l <= k / 2; ++l) {
        for (int i = 0; i < n * m; ++i) {
            if (!l) dp[i][l] = 0;
            else {
                dp[i][l] = mod * mod;
                for (auto &x : g[i])
                    dp[i][l] = min(dp[i][l], dp[x.first][l - 1] + x.second);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << 2 * dp[i * m + j][k / 2] << ' ';
        }
        cout << '\n';
    }
    return 0;
}