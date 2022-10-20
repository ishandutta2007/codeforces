#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

int n, m;
char s[N][N];
int hasInRow[N], hasInCol[N];

int used[N][N];

int inside(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= m;
}

void dfs(int u, int v) {
    used[u][v] = 1;
    for (int i = 0; i < 4; i++) {
        int uu = u + X[i];
        int vv = v + Y[i];
        if (!inside(uu, vv) || used[uu][vv] || s[uu][vv] != '#') continue;
        dfs(uu, vv);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    int found = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            found |= (s[i][j] == '#');
        }
    }
    if (!found) {
        cout << 0 << endl;
        return 0;
    }
    // check every row and col
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                hasInRow[i] = hasInCol[j] = 1;
            }
        }
    }
    int fullRow = 1;
    for (int i = 1; i <= n; i++) {
        fullRow &= hasInRow[i];
    }
    int fullCol = 1;
    for (int i = 1; i <= m; i++) {
        fullCol &= hasInCol[i];
    }

    if (fullCol || fullRow) {
        for (int i = 1; i <= n; i++) {
            if (!hasInRow[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (!hasInCol[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    //check 1 range
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 1; j <= m; j++) {
            num += (s[i][j] == '#' && s[i][j + 1] != '#');
        }
        if (num >= 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 1; j <= m; j++) {
        int num = 0;
        for (int i = 1; i <= n; i++) {
            num += (s[i][j] == '#' && s[i + 1][j] != '#');
        }
        if (num >= 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (used[i][j] || s[i][j] != '#') continue;
            dfs(i, j);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}