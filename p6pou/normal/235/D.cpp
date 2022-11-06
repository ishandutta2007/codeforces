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

const int MAX_N = 3000 + 5;

int N;
int E, elast[MAX_N], ey[MAX_N << 1], enext[MAX_N << 1], ee[2];
int n, p[MAX_N], vis[MAX_N], fath[MAX_N], dis[MAX_N];
int m, q[MAX_N];
vector<int> pq[MAX_N];
double ans1, ans2, inv[MAX_N];

int get_fath(int u) {
    return fath[u] ? fath[u] = get_fath(fath[u]) : u;
}
void add_edge(int x, int y) {
    ey[++ E] = y, enext[E] = elast[x], elast[x] = E;
    ey[++ E] = x, enext[E] = elast[y], elast[y] = E;
}
void dfs_init(int u, int fa, int vis_) {
    fath[u] = fa, vis[u] = vis_, q[++ m] = u;
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fa && !vis[v]) {
            dfs_init(v, u, vis_);
        }
    }
}
void dfs_solve(int u, int fa, int d) {
    dis[u] = d, ans1 += inv[d];
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fa && vis[v] == vis[u]) {
            dfs_solve(v, u, d + 1);
        }
    }
}

int main() {
    N = read_int();
    for (int i = 1; i <= N; i ++) {
        inv[i] = 1.0 / i;
    }
    for (int i = 1; i <= N; i ++) {
        int x = read_int() + 1, y = read_int() + 1;
        if (get_fath(x) != get_fath(y)) {
            fath[get_fath(x)] = get_fath(y);
            add_edge(x, y);
        } else {
            ee[0] = x, ee[1] = y;
        }
    }
    dfs_init(ee[0], 0, 0);
    for (int u = ee[1]; u; u = fath[u]) {
        p[++ n] = u, vis[u] = n;
    }
    for (int i = 1; i <= n; i ++) {
        m = 0;
        dfs_init(p[i], 0, i);
        for (int j = m; j >= 1; j --) {
            dfs_solve(q[j], 0, 1);
        }
        pq[i].insert(pq[i].end(), q + 1, q + 1 + m);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j < i; j ++) {
            int d1 = i - j - 1, d2 = n - i + j - 1;
            for (int x: pq[i]) {
                for (int y: pq[j]) {
                    ans2 += inv[dis[x] + dis[y] + d1];
                    ans2 += inv[dis[x] + dis[y] + d2];
                    ans2 -= inv[dis[x] + dis[y] + d1 + d2];
                }
            }
        }
    }
    printf("%.10lf\n", ans1 + ans2 * 2);
    return 0;
}