#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 1005;

int x[3], y[3];

int dist[MAXN + 1][MAXN + 1][3];
int dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

inline bool in(int l, int c) {
    return l >= 0 && c >= 0 && l <= MAXN && c <= MAXN;
}

inline void bfs(int x, int y, int t) {
    queue < pair <int, int> > Q;
    Q.push({x, y});
    dist[x][y][t] = 1;
    while(Q.size()) {
        int l = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int lin = l + dl[i], col = c + dc[i];
            if(in(lin, col) && dist[lin][col][t] == 0) {
                dist[lin][col][t] = dist[l][c][t] + 1;
                Q.push({lin, col});
            }
        }
    }
}

inline void way(int l, int c, int t, int lvl) {
    if(t == 0 && lvl == 1) {
        cout << l << " " << c << "\n";
    }
    if(lvl > 1) {
        cout << l << " " << c << "\n";
    }
    if(dist[l][c][t] == 1) {
        return ;
    }
    for(int i = 0; i < 4; i++) {
        int lin = l + dl[i], col = c + dc[i];
        if(in(lin, col) && dist[lin][col][t] + 1 == dist[l][c][t]) {
            way(lin, col, t, lvl + 1);
            return ;
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for(i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
        bfs(x[i], y[i], i);
    }
    int ans = 1e9;
    int l, c;
    for(i = 0; i <= MAXN; i++) {
        for(j = 0; j <= MAXN; j++) {
            int cur = 0;
            for(int p = 0; p < 3; p++) {
                cur += dist[i][j][p];
            }
            if(ans > cur) {
                ans = cur;
                l = i, c = j;
            }
        }
    }
    cout << ans - 2 << "\n";
    way(l, c, 0, 1);
    way(l, c, 1, 1);
    way(l, c, 2, 1);
    //cin.close();
    //cout.close();
    return 0;
}