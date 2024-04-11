#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N][N];

int inside(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= n;
}

int ask(int u, int v, int uu, int vv) {
    cout << "? " << u << ' ' << v << ' ' << uu << ' ' << vv << endl << flush;
    int res;
    cin >> res;
    return res;
}

int main() {
    cin >> n;
    memset(a, -1, sizeof a);
    a[1][1] = 1;
    a[n][n] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty()) {
        int u, v;
        tie(u, v) = q.front();
        q.pop();
        for (int i = 0; i <= 2; i++) {
            int uu = u + i;
            int vv = v + 2 - i;
            if (!inside(uu, vv) || a[uu][vv] != -1) continue;
            int now = ask(u, v, uu, vv);
            a[uu][vv] = a[u][v] ^ now ^ 1;
            q.push({uu, vv});
        }
    }
    a[1][2] = 0;
    a[2][3] = ask(1, 2, 2, 3) ^ 1;
    a[2][1] = ask(2, 1, 2, 3) ^ a[2][3] ^ 1;
    q.push({1, 2});
    q.push({2, 1});
    q.push({2, 3});
    while (!q.empty()) {
        int u, v;
        tie(u, v) = q.front();
        q.pop();
        for (int i = 0; i <= 2; i++) {
            int uu = u + i;
            int vv = v + 2 - i;
            if (!inside(uu, vv) || a[uu][vv] != -1) continue;
            int now = ask(u, v, uu, vv);
            a[uu][vv] = a[u][v] ^ now ^ 1;
            q.push({uu, vv});
        }
    }
    int rev = 0;
    int found = 0;
    for (int i = 1; i <= n && !found; i++) {
        for (int j = 1; j <= n && !found; j++) {
            // 0
            if (inside(i, j + 3) && (a[i][j] ^ a[i][j + 1] ^ a[i][j + 2] ^ a[i][j + 3]) == 0) {
                found = 1;
                int now = ask(i, j, i, j + 3);
                rev = a[i][j] ^ a[i][j + 3] ^ now ^ 1;
                break;
            }

            // 1
            if (inside(i + 1, j + 2) && ((a[i][j] ^ a[i][j + 1] ^ a[i][j + 2] ^ a[i + 1][j + 2]) == 0 || (a[i][j] ^ a[i + 1][j] ^ a[i + 1][j + 1] ^ a[i + 1][j + 2]) == 0)) {
                found = 1;
                int now = ask(i, j, i + 1, j + 2);
                rev = a[i][j] ^ a[i + 1][j + 2] ^ now ^ 1;
                break;
            }
            // 2
            if (inside(i + 2, j + 1) && ((a[i][j] ^ a[i][j + 1] ^ a[i + 1][j + 1] ^ a[i + 2][j + 1]) == 0 || (a[i][j] ^ a[i + 1][j] ^ a[i + 2][j] ^ a[i + 2][j + 1]) == 0)) {
                found = 1;
                int now = ask(i, j, i + 2, j + 1);
                rev = a[i][j] ^ a[i + 2][j + 1] ^ now ^ 1;
                break;
            }

            // 3
            if (inside(i + 3, j) && (a[i][j] ^ a[i + 1][j] ^ a[i + 2][j] ^ a[i + 3][j]) == 0) {
                found = 1;
                int now = ask(i, j, i + 3, j);
                rev = a[i][j] ^ a[i + 3][j] ^ now ^ 1;
                break;
            }
        }
    }
    assert(found == 1);
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) cout << a[i][j];
            else cout << (a[i][j] ^ rev);
        }
        cout << endl;
    }
    cout << flush;
    return 0;
}