#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e3;

int n, m, x, y;
string a[N + 1];
int stat[N + 1][2];

int dp[N + 1][N + 1][2];

int recurse(int pos, int k, int t) {
    if (pos == m - 1) {
        if (k < x) return 100000;
        return stat[pos][1-t];
    }
    if (dp[pos][k][t] != -1)
        return dp[pos][k][t];
    if (k < x)
        return dp[pos][k][t] = stat[pos][1-t] + recurse(pos + 1, k + 1, t);
    if (k == y)
        return dp[pos][k][t] = stat[pos][1-t] + recurse(pos + 1, 1, 1 - t);
    return dp[pos][k][t] = stat[pos][1-t] + min(recurse(pos + 1, k + 1, t), recurse(pos + 1, 1, 1 - t));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '#')
                stat[j][1] += 1;
            else stat[j][0] += 1;
        }
    }

    cout << min(recurse(0, 1, 0), recurse(0, 1, 1)) << "\n";
    return 0;
}