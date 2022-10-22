#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 510;
char s[V][V];
int rt[V * V];
int fd(int x) {
    if (x != rt[x]) rt[x] = fd(rt[x]);
    return rt[x];
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int _, n, m;

void add(int x, int y) {
    s[x][y] = 'X';
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= n) continue;
        if (ty < 0 || ty >= m) continue;
        //if (s[tx][ty] = 'X') U(x * m + y, tx * m + ty);
    }
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int st = 0;
        if (n % 3 == 0) ++st;
        //printf("%d\n", st);
        for (int i = st; i < n; i += 3) {
            for (int j = 0; j < m; ++j)
                s[i][j] = 'X';
            bool fd = false;
            if (i + 2 < n) {
                for (int j = 0; j < m && !fd; ++j) {
                    if (s[i + 1][j] == 'X') {
                        s[i + 2][j] = 'X';
                        //printf("FD1 %d\n", j);
                        fd = true;
                    }
                }
                for (int j = 0; j < m && !fd; ++j) {
                    if (s[i + 2][j] == 'X') {
                        s[i + 1][j] = 'X';
                        //printf("FD2 %d\n", j);
                        fd = true;
                    }
                }
                if (!fd) {
                    s[i + 1][0] = s[i + 2][0] = 'X';
                }
            }
        }
        for (int i = 0; i < n; ++i, puts(""))
            for (int j = 0; j < m; ++j)
                printf("%c", s[i][j]);
    }
    return 0;
}

/*
5
3 3
X.X
...
X.X
4 4
....
.X.X
....
.X.X
5 5
.X...
....X
.X...
.....
X.X.X
1 10
....X.X.X.
2 2
..
..
*/