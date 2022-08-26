#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 40;
const int md = 239;
const ll INF = 2e18;

int win[maxN][maxN][maxN][maxN];
int tox[maxN][maxN][maxN][maxN];
int toy[maxN][maxN][maxN][maxN];
int deg[maxN][maxN][maxN][maxN];
bool ended[maxN][maxN][maxN][maxN];

void solve() {
    int n, m;
    cin >> n >> m;
    range(i, n) range(j, m) range(e, n) range(w, m) {
                    win[i][j][e][w] = tox[i][j][e][w] = toy[i][j][e][w] = -1;
                }
    queue<ar<int, 4>> q;
    vector<int> dx = {-1, 1, -2, 2, -1, 1, -2, 2};
    vector<int> dy = {2, 2, 1, 1, -2, -2, -1, -1};
    int X = n / 2 - 1;
    int Y = m / 2 - 1;
    range(x1, n) range(y1, m) range(x2, n) range(y2, m) {
                    if (x1 == x2 && y1 == y2) {
                        win[x1][y1][x2][y2] = 0;
                        q.push({x1, y1, x2, y2});
                        ended[x1][y1][x2][y2] = true;
                        continue;
                    }
                    int xd = abs(x1 - x2);
                    int yd = abs(y1 - y2);
                    if (xd + yd == 3 && xd && yd) {
                        win[x1][y1][x2][y2] = 1;
                        tox[x1][y1][x2][y2] = x2;
                        toy[x1][y1][x2][y2] = y2;
                        q.push({x1, y1, x2, y2});
                        continue;
                    }
                    if (x1 == X && y1 == Y) {
                        win[x1][y1][x2][y2] = 1;
                        ended[x1][y1][x2][y2] = true;
                        q.push({x1, y1, x2, y2});
                        continue;
                    }
                    if (x2 == X + 1 && y2 == Y) {
                        win[x1][y1][x2][y2] = 0;
                        ended[x1][y1][x2][y2] = true;
                        q.push({x1, y1, x2, y2});
                        continue;
                    }
                    range(w, 8) {
                        int xx = x1 + dx[w];
                        int yy = y1 + dy[w];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                        deg[x1][y1][x2][y2]++;
                    }
                }
    while (!q.empty()) {
        auto[x1, y1, x2, y2] = q.front();
        q.pop();
        if (win[x1][y1][x2][y2]) {
            int xx1 = n - 1 - x2;
            int yy1 = y2;
            int xx2 = n - 1 - x1;
            int yy2 = y1;
            range(w, 8) {
                int xx = xx1 + dx[w];
                int yy = yy1 + dy[w];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (win[xx][yy][xx2][yy2] != -1) continue;
                if (!(--deg[xx][yy][xx2][yy2])) {
                    win[xx][yy][xx2][yy2] = 0;
                    q.push({xx, yy, xx2, yy2});
                }
            }
        } else {
            int xx1 = n - 1 - x2;
            int yy1 = y2;
            int xx2 = n - 1 - x1;
            int yy2 = y1;
            range(w, 8) {
                int xx = xx1 + dx[w];
                int yy = yy1 + dy[w];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (win[xx][yy][xx2][yy2] != -1) continue;
                win[xx][yy][xx2][yy2] = 1;
                tox[xx][yy][xx2][yy2] = xx1;
                toy[xx][yy][xx2][yy2] = yy1;
                q.push({xx, yy, xx2, yy2});
            }
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    if (win[x1][y1][x2][y2] == 1) {
        cout << "WHITE" << endl;
        while (true) {
            assert(win[x1][y1][x2][y2] == 1);
            if (ended[x1][y1][x2][y2]) return;
            int x11 = tox[x1][y1][x2][y2];
            int y11 = toy[x1][y1][x2][y2];
            cout << x11 + 1 << ' ' << y11 + 1 << endl;
            if (ended[n - 1 - x2][y2][n - 1 - x11][y11]) return;
            int x22, y22;
            cin >> x22 >> y22;
            if (x22 == -1) exit(0);
            x1 = x11;
            y1 = y11;
            x2 = x22 - 1;
            y2 = y22 - 1;
        }
    } else {
        cout << "BLACK" << endl;
        swap(x1, x2);
        swap(y1, y2);
        x1 = n - 1 - x1;
        x2 = n - 1 - x2;
        cin >> x2 >> y2;
        x2--;
        y2--;
        x2 = n - 1 - x2;
        while (true) {
            assert(win[x1][y1][x2][y2] == 1);
            if (ended[x1][y1][x2][y2]) return;
            int x11 = tox[x1][y1][x2][y2];
            int y11 = toy[x1][y1][x2][y2];
            cout << n - x11 << ' ' << y11 + 1 << endl;
            if (ended[n - 1 - x2][y2][n - 1 - x11][y11]) return;
            int x22, y22;
            cin >> x22 >> y22;
            if (x22 == -1) exit(0);
            x1 = x11;
            y1 = y11;
            x2 = x22 - 1;
            y2 = y22 - 1;
            x2 = n - x2 - 1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}