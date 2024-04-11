#include <bits/stdc++.h>
using namespace std;
#define left oopsTakenWord
 
int n, m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<vector<int>> grid;
vector<vector<int>> left, up;
int si, sj, ti, tj;
 
void dfs(int i, int j, int d, int t) {
    if (t > 1 || i < 1 || i > n || j < 1 || j > m || grid[i][j] == 1)
        return;

    if (j == tj) {
        int occ = up[max(ti, i)][j] - up[min(ti, i) - 1][j];
        if (occ == 0) {
            cout << "YES";
            exit(0);
        }
    }
	else if (i == ti) {
        int occ = left[i][max(tj, j)] - left[i][min(tj, j) - 1];
        if (occ == 0) {
            cout << "YES";
            exit(0);
        }
    }
    for (int d1 = 0; d1 < 4; d1++) {
        if (d1 == d || d1 == (d ^ 1)) continue;
        dfs(i + dy[d1], j + dx[d1], d1, t + 1);
    }
    dfs(i + dy[d], j + dx[d], d, t);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    grid.assign(n + 1, vector<int>(m + 1, 0));
    string inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        for (int j = 0; j < m; j++) {
            if (inp[j] == '*') {
                grid[i + 1][j + 1] = 1;
            }
            if (inp[j] == 'S') {
                si = i + 1;
                sj = j + 1;
            } else if (inp[j] == 'T') {
                ti = i + 1;
                tj = j + 1;
            }
        }
    }
    left.assign(n + 1, vector<int>(m + 1, 0));
    up.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            left[i][j] = left[i][j - 1] + grid[i][j];
            up[i][j] = up[i - 1][j] + grid[i][j];
        }
    }
    for (int d = 0; d < 4; d++) {
        dfs(si + dy[d], sj + dx[d], d, 0);
    }
    cout << "NO";
}