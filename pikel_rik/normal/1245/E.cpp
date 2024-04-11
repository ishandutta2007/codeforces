#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 10;

int n = 10, a[N][N], point[N*N];
ld dp[N*N][2];

int idx(int i, int j) {
    if (i & 1)
        return (9 - i) * 10 + j;
    return (9 - i) * 10 + 9 - j;
}

void addEdge(int u, int v) {
    point[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(point, -1, sizeof(point));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                addEdge(idx(i, j), idx(i - a[i][j], j));
            }
        }
    }

    dp[99][0] = 0;
    dp[99][1] = 1e9;

    for (int i = 98; i >= 0; i--) {
        dp[i][1] = 1e9;
        if (point[i] != -1)
            dp[i][1] = dp[point[i]][0];
        int c = 0;
        for (int j = 1; i + j <= min(99, i + 6); j++) {
            dp[i][0] += (1 + min(dp[i + j][0], dp[i + j][1])) / 6;
            c++;
        }
        dp[i][0] = 6 * (dp[i][0] + 1 - c / 6.0) / c;
    }

    cout << fixed << setprecision(12);
    cout << min(dp[0][0], dp[0][1]);
    return 0;
}