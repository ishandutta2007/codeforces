#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 600 + 5;
const int INF32 = 1.01e9;

int N, M;
struct Edge {
    int a, b, c;
    bool operator < (Edge &t) const {
        return b < t.b;
    }
};
vector<Edge> e[MAX_N];
int ek[MAX_N][MAX_N];
int f[MAX_N];


int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i ++) {
        Edge t;
        scanf("%d%d%d", &t.a, &t.b, &t.c);
        e[t.a].push_back(t);
    }
    for (int x = 0; x < N; x ++) {
        vector<Edge> ex;
        ex.swap(e[x]);
        sort(ex.begin(), ex.end());
        int m = ex.size();
        for (int i = 0; i < m; i ++) {
            int ok = 1;
            for (int j = 0; j < m && ok; j ++) {
                if (i == j) continue;
                int c = (ex[i].b - ex[j].b + N) % N + ex[j].c;
                if (c <= ex[i].c) ok = 0;
            }
            if (ok) e[x].push_back(ex[i]);
        }
        // printf("x=%d, m=%d, mm=%d\n", x, m, e[x].size());
        m = e[x].size();
        sort(e[x].begin(), e[x].end());
        // for (int j = 0; j < m; j ++) {
        //     printf("(%d,%d,%d)\n", e[x][j].a, e[x][j].b, e[x][j].c);
        // }
        for (int y = 0, j = m - 1; y < N; y ++) {
            if (e[x][(j + 1) % m].b == y) {
                j ++, j -= j == m ? m : 0;
            }
            // printf("x=%d, y=%d, j=%d\n", x, y, j);
            ek[x][y] = j;
        }
    }
    for (int s = 0; s < N; s ++) {
        // printf("s=%d\n", s);
        // for (int j = 0; j < (int)e[s].size(); j ++) {
        //     printf("    (%d,%d,%d)\n", e[s][j].a, e[s][j].b, e[s][j].c);
        // }
        for (int x = 0; x < N; x ++) {
            f[x] = INF32;
        }
        f[s] = 0;
        static int fok[MAX_N];
        for (int i = 0; i < N; i ++) {
            int tx = INF32, x = -1;
            for (int y = 0; y < N; y ++) {
                if (fok[y] != ~s && f[y] < tx) {
                    tx = f[y], x = y;
                }
            }
            // printf("    i=%d, x=%d, tx=%d\n", i, x, tx);
            fok[x] = ~s;
            tx = f[x] % N;
            for (int y = 0; y < N; y ++) {
                int y0 = (y - tx + N) % N;
                int k = ek[x][y0];
                int ty = f[x] + (y0 - e[x][k].b + N) % N + e[x][k].c;
                // printf("        x=%d,f[x]=%d, y=%d,y0=%d,k=%d,ty=%d\n", x, f[x], y, y0, k, ty);
                if (f[y] > ty) f[y] = ty;
            }
        }
        for (int x = 0; x < N; x ++) {
            printf("%d%c", f[x], x + 1 < N ? ' ' : '\n');
        }
    }
    return 0;
}