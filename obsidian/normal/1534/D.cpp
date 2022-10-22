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
const int V = 2100;
int d[V][V], n, f[V];
int a[V], b[V], m;

int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}

void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return;
    f[px] = py;
}

vector<int> g[V];
void Q(int u) {
    printf("? %d\n", u);
    fflush(stdout);
    for (int i = 1; i <= n; ++i) scanf("%d", &d[u][i]);
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= n; ++i) g[d[u][i]].PB(i);
    int last = 1;
    while (g[last].size() == 1) ++last;
    for (int i = 1; i <= last; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (fd(g[i - 1][0]) == fd(g[i][j])) continue;
            a[m] = g[i - 1][0];
            b[m++] = g[i][j];
            U(u, g[i][j]);
        }

    }
}

void OUT() {
    puts("!");
    for (int i = 0; i < m; ++i) printf("%d %d\n", a[i], b[i]);
    fflush(stdout);
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) f[i] = i;
        m = 0;
        Q(1);
        while (1) {
            int id = -1;
            for (int i = 1; i <= n; ++i) if (fd(i) != fd(1) && (id == -1 || d[1][id] > d[1][i])) id = i;
            if (id == -1) break;
            Q(id);
        }
        OUT();
    }
    return 0;
}

/*

*/