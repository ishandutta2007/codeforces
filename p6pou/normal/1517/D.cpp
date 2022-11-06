#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500 + 5;
const int MAX_V = 250000 + 5;
const int MAX_E = 1000000 + 5;
const int INF32 = 1e9;

int N, M, K;
int id[MAX_N][MAX_N];
int E, elast[MAX_V];
struct Edge {
    int y, z, next;
} e[MAX_E];

void add_edge(int x, int y, int z) {
    e[++ E].y = y;
    e[E].z = z;
    e[E].next = elast[x];
    elast[x] = E;
    e[++ E].y = x;
    e[E].z = z;
    e[E].next = elast[y];
    elast[y] = E;
}
int solve(int x0, int y0) {
    static int n[2], ver[2][MAX_V], dis[2][MAX_V];
    ver[0][1] = id[x0][y0];
    dis[0][id[x0][y0]] = 0;
    n[0] = 1, n[1] = 0;
    for (int k = 1; k <= K; k ++) {
        int *v0 = ver[~k & 1], *v1 = ver[k & 1];
        int *d0 = dis[~k & 1], *d1 = dis[k & 1];
        int &n0 = n[~k & 1], &n1 = n[k & 1];
        auto push_into_v1 = [&] (int x, int y) {
            if (1 <= x && x <= N && 1 <= y && y <= M) {
                v1[++ n1] = id[x][y];
            }
        };
        for (int i = 0; i < k; i ++) {
            push_into_v1(x0 - i, y0 + k - i);
            push_into_v1(x0 - k + i, y0 - i);
            push_into_v1(x0 + i, y0 - k + i);
            push_into_v1(x0 + k - i, y0 + i);
        }
        for (int i = 1; i <= n1; i ++) {
            d1[v1[i]] = INF32;
        }
        for (int i = 1; i <= n0; i ++) {
            for (int j = elast[v0[i]]; j; j = e[j].next) {
                d1[e[j].y] = min(d1[e[j].y], d0[v0[i]] + e[j].z);
            }
        }
    }
    int res = INF32, nk = n[K & 1];
    int *vk = ver[K & 1], *dk = dis[K & 1];
    for (int i = 1; i <= nk; i ++) {
        res = min(res, dk[vk[i]]);
    }
    return res;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    if (K & 1) {
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= M; j ++) {
                printf("-1%c", j < M ? ' ' : '\n');
            }
        }
        return 0;
    }
    for (int i = 1, k = 0; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            id[i][j] = ++ k;
        }
    }
    K >>= 1;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1, t; j < M; j ++) {
            scanf("%d", &t);
            add_edge(id[i][j], id[i][j + 1], t);
        }
    }
    for (int i = 1; i < N; i ++) {
        for (int j = 1, t; j <= M; j ++) {
            scanf("%d", &t);
            add_edge(id[i][j], id[i + 1][j], t);
        }
    }
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            int res = solve(i, j);
            printf("%d%c", res << 1, j < M ? ' ' : '\n');
        }
    }
    fprintf(stderr, "clock=%d\n", clock());
    return 0;
}