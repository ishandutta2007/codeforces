#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))

int dx[] = {-1, -0, +0, +1};
int dy[] = {-0, -1, +1, +0};

const int maxn = 50;
string s[maxn];
int h[maxn][maxn],
    up[maxn][maxn];
bool mark[maxn][maxn];
int n, m;
bool found;

bool is_valid(int x, int y) {
    return 0 <= x and x < n
        and 0 <= y and y < m
        and s[x][y] == '#';
}

void dfs(int x, int y, int px = -1, int py = -1) {
    mark[x][y] = true;
    up[x][y] = h[x][y];
    int child_cnt = 0;
    bool is_cut = false;
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (!is_valid(xx, yy) or (xx == px and yy == py))
            continue;
        if (mark[xx][yy])
            smin(up[x][y], up[xx][yy]);
        else {
            h[xx][yy] = h[x][y] + 1;
            dfs(xx, yy, x, y);
            child_cnt++;
            smin(up[x][y], up[xx][yy]);
            if (up[xx][yy] >= h[x][y])
                is_cut = true;
        }
    }
    if (px == -1 and py == -1)
        is_cut = child_cnt > 1;
    if (is_cut)
        found = true;
}

int main() {
    cin >> n >> m;
    pii source;
    int colcnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        colcnt += count(s[i].begin(), s[i].end(), '#');
        for (int j = 0; j < m; j++)
            if (s[i][j] == '#')
                source = pii(i, j);
    }
    dfs(source.L, source.R);
    if (found)
        cout << 1 << endl;
    else if (colcnt <= 2)
        cout << -1 << endl;
    else
        cout << 2 << endl;
    return 0;
}