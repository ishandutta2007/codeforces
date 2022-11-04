#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

vector <int> g[MAXN + 1];

int dst[MAXN + 1][MAXN + 1];
int q[MAXN * MAXN + 1];
bool ok[MAXN + 1][MAXN + 1];

inline void bfs(int nod) {
    int b = 0, e = 0;
    dst[nod][nod] = 1;
    q[e++] = nod;
    while(b < e) {
        int x = q[b];
        b++;
        for(auto it : g[x]) {
            if(dst[nod][it] == 0) {
                dst[nod][it] = dst[nod][x] + 1;
                q[e++] = it;
            }
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, s, t, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        ok[x][y] = ok[y][x] = 1;
    }
    for(i = 1; i <= n; i++) {
        bfs(i);
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            dst[i][j]--;
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i != j && dst[s][t] <= min(dst[s][i] + dst[j][t] + 1, dst[s][j] + dst[i][t] + 1) && ok[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << ans / 2;
    //cin.close();
    //cout.close();
    return 0;
}