#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, k;
int mp[N][N];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {0, 0, 1, 0};
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) 
        scanf("%d", &mp[j][i]);
    for (int i = 1, x, y, t; i <= k; ++i) {
        scanf("%d", &x);
        y = 1;
        while (y <= n) {
            t = mp[x][y];
            mp[x][y] = 2;
            x += dx[t]; y += dy[t];
        }
        printf("%d ", x);
    }
    puts("");
    return 0;
}