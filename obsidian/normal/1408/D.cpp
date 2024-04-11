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
const int oo = 1000000000;
const int P = 1000000007;
const int V = 2100;

struct Node {
    int dx, dy, id;
}e[V * V];

bool cmp(Node x, Node y) {
    if (x.dx != y.dx) return x.dx < y.dx;
    return x.dy < y.dy;
}

int a[V], b[V], c[V], d[V], mx[V], cnt[V];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
        for (int i = 0; i < m; ++i) scanf("%d%d", &c[i], &d[i]);
        for (int i = 0; i < n; ++i) {
            mx[i] = 0;
            for (int j = 0; j < m; ++j) {
                e[i * m + j].dx = max(0, c[j] - a[i] + 1);
                e[i * m + j].dy = max(0, d[j] - b[i] + 1);
                e[i * m + j].id = i;
                mx[i] = max(mx[i], e[i * m + j].dy);
            }
        }
        sort(e, e + n * m, cmp);
        int ans = oo;
        for (int i = 0; i < n; ++i) cnt[i] = m;
        int t_mx = 0;
        for (int i = n * m; i >= 0; --i) {
            if (i != n * m) {
                    /*
                cnt[e[i].id]--;
                if (cnt[e[i].id] == 0) {
                    t_mx = max(t_mx, mx[e[i].id]);
                }*/
                t_mx = max(t_mx, e[i].dy);
            }
            //printf("E %d %d %d %d\n", e[i].dx, e[i].dy, e[i].id, t_mx);
            int t_x = 0;
            if (i != 0) t_x = e[i - 1].dx;
            ans = min(ans, t_mx + t_x);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
1 1
0 0
2 3

2 3
1 6
6 1
10 1
1 10
7 7

1 2
0 0
0 0
0 0

7 3
0 8
3 8
2 7
0 10
5 5
7 0
3 5
6 6
3 11
11 5
*/