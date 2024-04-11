#include <bits/stdc++.h>

using namespace std;

const int N = 260;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

int n, m, q, p;
char s[N][N];
int a[N][N];
int used[N][N], cnt;

bool check(int u, int v) {
    if (u < 1 || u > n || v < 1 || v > m) {
        return 0;
    }
    if (s[u][v] == '*') {
        return 0;
    }
    return 1;
}

void go(int uu, int vv) {
    struct data {
        int y, x, val;
        data(){};
        data(int u, int v, int val) {
            this->x = u;
            this->y = v;
            this->val = val;
        }
    };
    queue <data> ss;
    ss.push(data(uu, vv, q * ((int)s[uu][vv] - 'A' + 1)));
    cnt++;
    used[uu][vv] = cnt;
    while (!ss.empty()) {
        data u = ss.front();
        ss.pop();
        a[u.x][u.y] += u.val;
        if (u.val > 1) {
            for (int i = 0; i < 4; i++) {
                int xx = u.x + dirX[i];
                int yy = u.y + dirY[i];
                int zz = u.val / 2;
                if (check(xx, yy)) {
                    if (used[xx][yy] < cnt) {
                        ss.push(data(xx, yy, zz));
                        used[xx][yy] = cnt;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &q, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] <= 'Z' && s[i][j] >= 'A') {
                go(i, j);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res += a[i][j] > p;
        }
    }
    cout << res << endl;
    return 0;
}