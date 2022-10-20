#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 510

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, cnt;
string s[N];
stringstream res;

void DFS(int x, int y, bool R = 1) {
    res << "B " << x << " " << y << endl;
    cnt++;
    s[x][y] = '#';
    for(int i = 0; i < 4; i++) {
        int x2 = x + dir[i][0];
        int y2 = y + dir[i][1];
        if(s[x2][y2] == '.' && x2 && y2 && x2 <= n && y2 <= m)
            DFS(x2, y2);
    }
    if(R) {
        cnt += 2;
        res << "D " << x << " " << y << endl;
        res << "R " << x << " " << y << endl;
    }
}

int main() {
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] = '#' + s[i] + '#';
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(s[i][j] == '.')
            DFS(i, j, 0);
    cout << cnt << endl << res.str();
    return 0;
}