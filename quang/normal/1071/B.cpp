#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, k;
char a[N][N];
int cnt[N][N];
int pos[N][N];
pair<int, int> nxt[N][N];

bool inside(int u, int v) {
    return (u >= 1 && u <= n && v >= 1 && v <= n);
}
bool cmp(pair<int, int> &u, pair<int, int> &v) {
    if (a[u.first][u.second] != a[v.first][v.second]) {
        return a[u.first][u.second] < a[v.first][v.second];
    }
    pair<int, int> &uu = nxt[u.first][u.second];
    pair<int, int> &vv = nxt[v.first][v.second];
    return pos[uu.first][uu.second] < pos[vv.first][vv.second];
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                cnt[i][j] = 0;
            } else {
                int foo = 1e9;
                if (inside(i - 1, j)) {
                    foo = min(foo, cnt[i - 1][j]);
                }
                if (inside(i, j - 1)) {
                    foo = min(foo, cnt[i][j - 1]);
                }
                cnt[i][j] = foo;
            }
            cnt[i][j] += (a[i][j] != 'a');
            if (cnt[i][j] <= k) {
                a[i][j] = 'a';
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%s\n", (a[i] + 1));
    // }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            pos[i][j] = 1e9;
        }
    }
    pos[n][n] = 0;
    for (int sum = n + n - 1; sum >= 2; sum--) {
        vector<pair<int, int> > foo;
        for (int i = 1; i <= n; i++) {
            int j = sum - i;
            if (!inside(i, j)) {
                continue;
            }
            nxt[i][j] = (pos[i + 1][j] < pos[i][j + 1] ? make_pair(i + 1, j) : make_pair(i, j + 1));
            foo.push_back({i, j});
        }
        sort(foo.begin(), foo.end(), cmp);
        int cnt = 0;
        for (pair<int, int> u : foo) {
            pos[u.first][u.second] = cnt++;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x = 1, y = 1;
    for (int i = 1; i <= n * 2 - 1; i++) {
        printf("%c", a[x][y]);
        int xx = nxt[x][y].first;
        int yy = nxt[x][y].second; 
        x = xx;
        y = yy;
    }
    printf("\n");
    return 0;
}