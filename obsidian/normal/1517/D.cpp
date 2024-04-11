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
const int oo = 1e9;
const int V = 510;
int d[V][V][12], n, m, K, a[V][V], b[V][V];

int main() {
    while (~scanf("%d%d%d", &n, &m, &K)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j)
                scanf("%d", &a[i][j]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                scanf("%d", &b[i][j]);
        }
        if (K % 2 == 1) {
            for (int i = 0; i < n; ++i, puts(""))
                for (int j = 0; j < m; ++j)
                    printf("-1 ");
            continue;
        }
        K /= 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k <= K; ++k)
                    d[i][j][k] = oo;
                d[i][j][0] = 0;
            }
        }
        for (int k = 0; k < K; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                        //printf("D %d %d %d %d\n", i, j, k, d[i][j][k]);
                    if (i > 0) d[i - 1][j][k + 1] = min(d[i - 1][j][k + 1], d[i][j][k] + b[i][j]);
                    if (i < n - 1) d[i + 1][j][k + 1] = min(d[i + 1][j][k + 1], d[i][j][k] + b[i + 1][j]);
                    if (j > 0) d[i][j - 1][k + 1] = min(d[i][j - 1][k + 1], d[i][j][k] + a[i][j]);
                    if (j < m - 1) d[i][j + 1][k + 1] = min(d[i][j + 1][k + 1], d[i][j][k] + a[i][j + 1]);
                }
            }
        }
        for (int i = 0; i < n; ++i, puts(""))
                for (int j = 0; j < m; ++j)
                    printf("%d ", d[i][j][K] * 2);
    }
    return 0;
}

/*
3 3 10
1 1
1 1
1 1
1 1 1
1 1 1

2 2 4
1
3
4 2

2 2 3
1
2
3 4
*/