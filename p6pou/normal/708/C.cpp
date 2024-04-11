#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

const int MAX_N = 400000 + 5;

int N;
int elast[MAX_N];
struct Edge {
    int y, next;
} e[MAX_N << 1];
int siz[MAX_N], son[MAX_N], f[MAX_N], g[MAX_N];

void dp_inside(int u, int fa) {
    siz[u] = 1;
    for (int j = elast[u]; j; j = e[j].next) {
        int v = e[j].y;
        if (v != fa) {
            dp_inside(v, u);
            siz[u] += siz[v];
            son[u] = siz[v] << 1 > N ? v : son[u];
            f[u] = max(f[u], siz[v] << 1 <= N ? siz[v] : f[v]);
        }
    }
    son[u] = N - siz[u] << 1 > N ? fa : son[u];
}
void dp_outside(int u, int fa) {
    int v1 = fa, f1 = g[u], v2 = 0, f2 = 0;
    for (int j = elast[u]; j; j = e[j].next) {
        int v = e[j].y;
        if (v != fa) {
            int t = siz[v] << 1 <= N ? siz[v] : f[v];
            f1 < t ? f2 = f1, v2 = v1, f1 = t, v1 = v :
            f2 < t ? f2 = t, v2 = v : 0;
        }
    }
    for (int j = elast[u]; j; j = e[j].next) {
        int v = e[j].y;
        if (v != fa) {
            g[v] = N - siz[v] << 1 <= N ? N - siz[v] : v != v1 ? f1 : f2;
            dp_outside(v, u);
        }
    }
}

int main() {
    N = read_int();
    for (int i = 1, j = 1; i < N; i ++) {
        int x = read_int();
        int y = read_int();
        e[j].y = y;
        e[j].next = elast[x];
        elast[x] = j ++;
        e[j].y = x;
        e[j].next = elast[y];
        elast[y] = j ++;
    }
    dp_inside(1, 0);
    dp_outside(1, 0);
    for (int i = 1; i <= N; i ++) {
        int res = 0;
        if (!son[i]) {
            res = 1;
        } else if (siz[son[i]] < siz[i]) {
            res = siz[son[i]] - f[son[i]] << 1 <= N;
        } else {
            res = N - siz[i] - g[i] << 1 <= N;
        }
        printf("%d%c", res, i < N ? ' ' : '\n');
    }
    return 0;
}