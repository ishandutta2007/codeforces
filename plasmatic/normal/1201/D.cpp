// ./d-treasure-hunting.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int R, C, K, Q,
    rmin[MN], rmax[MN];
ll dp[MN][2];
set<int> safe, _rows;
vector<int> rows;

bool valid(int c) { return c && c != INF; }
int P(int r, int p) {
    return p ? rmax[rows[r]] : rmin[rows[r]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K >> Q;
    memset(rmin, 0x3f, sizeof rmin);
    for (auto i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        rmin[r] = min(rmin[r], c);
        rmax[r] = max(rmax[r], c);
        _rows.insert(r);
    }
    _rows.insert(1);
    rmin[1] = 1;
    rmax[1] = max(rmax[1], 1);
    for (auto i = 0; i < Q; i++) {
        int c; cin >> c;
        safe.insert(c);
    }
    safe.insert(0);
    safe.insert(INF);

    int sz = _rows.size();
    rows = vector<int>(_rows.begin(), _rows.end());
    dp[0][0] = 2 * rmax[rows[0]] - 2 * rmin[rows[0]];
    dp[0][1] = rmax[rows[0]] - rmin[rows[0]];
    for (auto i = 1; i < sz; i++) {
        int r = rows[i], yd = rows[i] - rows[i-1];
        dp[i][0] = dp[i][1] = LLINF;
        for (auto j = 0; j < 2; j++) {
            for (auto k = 0; k < 2; k++) {
                auto nxt = safe.lower_bound(P(i-1, k)), pre = prev(nxt);
                for (auto safeCol : {*pre, *nxt})
                    if (valid(safeCol))
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(P(i-1, k) - safeCol) + abs(safeCol - P(i, !j)) + abs(P(i, !j) - P(i, j)) + yd);
            }
        }
    }

    cout << min(dp[sz-1][0], dp[sz-1][1]) << '\n'; // start from (1, 1) not (1, 0)

    return 0;
}