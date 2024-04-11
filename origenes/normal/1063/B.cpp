#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 10;

int d[N][N];

int n, m, r, c, x, y;

string s[N];

struct Node {
    int r, c;
};

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r >> c >> x >> y;
    r--; c--;
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(d, 0x3f, sizeof(d));
    queue<Node> q;
    d[r][c] = 0;
    q.push({ r, c });

    while (!q.empty()) {
        Node u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int rr = u.r + dr[i];
            int cc = u.c + dc[i];
            if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue;
            if (s[rr][cc] == '*') continue;
            int val = d[u.r][u.c];
            if (i == 1) val++;
            if (d[rr][cc] > val) {
                d[rr][cc] = val;
                q.push({ rr, cc });
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.') {
                if (d[i][j] <= x && j - c + d[i][j] <= y) ans++;
            }
    cout << ans << '\n';
    return 0;
}