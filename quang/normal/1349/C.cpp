#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};
const int INF = 1e9;

int n, m, t;
char s[N][N];
int firstTime[N][N];
int used[N][N];

bool inside(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            firstTime[i][j] = INF;
        }
    }
    priority_queue<pair<int, pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool found = 0;
            for (int dir = 0; dir < 4; dir++) {
                int ii = i + X[dir];
                int jj = j + Y[dir];
                if (!inside(ii, jj)) continue;
                if (s[i][j] == s[ii][jj]) {
                    found = 1;
                }
            }
            if (found) {
                firstTime[i][j] = 0;
                q.push({0, {i, j}});
            }
        }
    }
    while (!q.empty()) {
        int u, v;
        tie(u, v) = q.top().second;
        q.pop();
        if (used[u][v]) continue;
        used[u][v] = 1;
        for (int dir = 0; dir < 4; dir++) {
            int uu = u + X[dir];
            int vv = v + Y[dir];
            if (!inside(uu, vv)) continue;
            int now = firstTime[u][v] + (s[u][v] != s[uu][vv]);
            if (now < firstTime[uu][vv]) {
                firstTime[uu][vv] = now;
                q.push({-firstTime[uu][vv], {uu, vv}});
            }
        }
    }


    while (t--) {
        int u, v;
        long long p;
        cin >> u >> v >> p;
        if (firstTime[u][v] >= INF) {
            cout << s[u][v] << '\n';
        } else {
            int res = (s[u][v] == '1');
            if ((p - firstTime[u][v]) % 2 == 1) res ^= 1;
            cout << res << '\n';
        }
    }
    return 0;
}