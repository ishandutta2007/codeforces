#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> vis;

int ask(int x1, int y1, int x2, int y2) {
    if (x1 > n || y1 > n || x2 > n || y2 > n) return -1;
    if (x1 > x2 || y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int ans; cin >> ans;
    if (ans == -1) exit(0);
    return ans;
}

vector<int> dx = {-2, 0, 1, 2, 0, -1};
vector<int> dy = {0, 2, 1, 0, -2, -1};

void dfs(int x, int y, int px, int py, vector<vector<int>> &a) {
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (vis[x][y]) return;
    vis[x][y] = 1;

    // determine x, y based on px, py
    if (px != 0 && py != 0) {
        int sm = ask(x, y, px, py);
        if (sm) a[x][y] = a[px][py];
        else a[x][y] = a[px][py] ^ 1;
    }

    for (int i = 0; i < 6; i++) {
        dfs(x + dx[i], y + dy[i], x, y, a);
    }
}

signed main() {

    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    vis = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    a[1][1] = 1;

    // every question we determine one cell
    for (int i = 1; i < n; i += 2) {
        int same = ask(1, i, 1, i+2);
        if (same) {
            a[1][i+2] = a[1][i];
        } else {
            a[1][i+2] = a[1][i]^1;
        }
    }

    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= n; j += 2) {
            int same = ask(i, j, i+1, j+1);
            if (same == 1) {
                a[i+1][j+1] = a[i][j];
            } else if (same == 0) {
                a[i+1][j+1] = a[i][j] ^ 1;
            }

            same = ask(i, j, i+2, j);
            if (same == 1) {
                a[i+2][j] = a[i][j];
            } else if (same == 0) {
                a[i+2][j] = a[i][j] ^ 1;
            }
        }
    }

    //cout << "phase 1 done\n";

    // go along the diagonals
    // find any submatrix of the form
    // 1??    1??
    // ?0? or ?1?
    // ??0    ??0

    // ask 2,1 and 2,3
    // then ask 2*3 matrix
    // if same
    // ask matrix with same center as corner
    // else
    // ask matrix with different center as corner

    int px, py;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] == 1 && a[i+2][i+2] == 0) {
            // ask this one
            int same = ask(i+1, i, i+1, i+2);

            if (same == 0) {
                // not same
                int s2;
                if (a[i+1][i+1] != a[i][i]) {
                    s2 = ask(i, i, i+1, i+2);
                    px = i+1, py = i+2;
                    if (s2) {
                        a[i+1][i+2] = 1;
                    } else {
                        a[i+1][i+2] = 0;
                    }
                } else {
                    s2 = ask(i+1, i, i+2, i+2);
                    px = i+1, py = i;
                    if (s2) {
                        a[i+1][i] = 0;
                    } else {
                        a[i+1][i] = 1;
                    }
                }
            } else {
                // same
                int s2;
                if (a[i+1][i+1] == a[i][i]) {
                    s2 = ask(i, i, i+1, i+2);
                    px = i+1, py = i+2;
                    if (s2) {
                        a[i+1][i+2] = 1;
                    } else {
                        a[i+1][i+2] = 0;
                    }
                } else {
                    s2 = ask(i+1, i, i+2, i+2);
                    px = i+1, py = i;
                    if (s2) {
                        a[i+1][i] = 0;
                    } else {
                        a[i+1][i] = 1;
                    }
                }
            }

            break;
        }
    }

    // then dfs from px, py
    dfs(px, py, 0, 0, a);

    cout << "!\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << endl;

    return 0;
}