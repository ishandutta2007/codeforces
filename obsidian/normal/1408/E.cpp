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

const int V = 200100;
struct Edge{
    int u, v, len;
}e[V];

bool cmp(Edge x, Edge y) {
    return x.len > y.len;
}

int f[V];
int fd(int x) {
    if (x != f[x]) f[x] = fd(f[x]);
    return f[x];
}
void U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px != py) f[py] = px;
}

int a[V], b[V], n, m, x, y;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n + m; ++i) f[i] = i;
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
        LL s = 0;
        int K = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            for (int j = 1; j <= x; ++j) {
                scanf("%d", &y);
                s += a[i] + b[y];
                e[K].u = i + m;
                e[K].v = y;
                e[K].len = a[i] + b[y];
                ++K;
            }
        }
        sort(e, e + K, cmp);
        for (int i = 0; i < K; ++i) {
            if (fd(e[i].u) != fd(e[i].v)) {
                s -= e[i].len;
                U(e[i].u, e[i].v);
            }
        }
        printf("%I64d\n", s);
    }
    return 0;
}

/*
3 2
1 2 3
4 5
2 1 2
2 1 2
2 1 2

7 8
3 6 7 9 10 7 239
8 1 9 7 10 2 6 239
3 2 1 3
2 4 1
3 1 3 7
2 4 3
5 3 4 5 6 7
2 5 7
1 8
*/