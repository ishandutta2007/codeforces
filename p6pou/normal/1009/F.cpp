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

char wb[BUFFER_SIZE], *wp = wb;
inline void write_flush() {
    fwrite(wb, 1, wp - wb, stdout);
    wp = wb;
}
inline void write_char(char c) {
    *wp ++ = c;
    if (wp == wb + BUFFER_SIZE) {
        write_flush();
    }
}
inline void write_int(int x) {
    if (x == 0) {
        write_char('0');
    } else if (x < 0) {
        write_char('-');
        x = -x;
    }
    static char b[32], i;
    for (i = 1; x; i ++) {
        b[i] = x % 10 + '0';
        x /= 10;
    }
    for (i --; i; i --) {
        write_char(b[i]);
    }
}

const int MAX_N = 1000000 + 5;

int N;
int elast[MAX_N], ey[MAX_N << 1], enext[MAX_N << 1];
int fath[MAX_N], hei[MAX_N], son[MAX_N];
int f_[MAX_N], ans[MAX_N];

void dfs_tcp_1(int u, int fa) {
    fath[u] = fa;
    hei[u] = 1;
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fa) {
            dfs_tcp_1(v, u);
            if (hei[u] <= hei[v]) {
                son[u] = v;
                hei[u] = hei[v] + 1;
            }
        }
    }
}
void dfs_tcp_2(int u, int f[]) {
    f[0] = 1;
    ans[u] = 0;
    if (son[u]) {
        dfs_tcp_2(son[u], f + 1);
        if (f[ans[u]] < f[1 + ans[son[u]]]) {
            ans[u] = 1 + ans[son[u]];
        }
    }
    for (int j = elast[u]; j; j = enext[j]) {
        int v = ey[j];
        if (v != fath[u] && v != son[u]) {
            dfs_tcp_2(v, f + hei[u]);
            int *g = f + hei[u];
            for (int i = hei[v] - 1; i >= 0; i --) {
                if ((f[1 + i] += g[i]) >= f[ans[u]]) {
                    ans[u] = 1 + i;
                }
            }
        }
    }
}

int main() {
    N = read_int();
    for (int i = 1, j = 1; i < N; i ++) {
        int x = read_int();
        int y = read_int();
        ey[j] = y;
        enext[j] = elast[x];
        elast[x] = j ++;
        ey[j] = x;
        enext[j] = elast[y];
        elast[y] = j ++;
    }
    dfs_tcp_1(1, 0);
    dfs_tcp_2(1, f_);
    for (int i = 1; i <= N; i ++) {
        write_int(ans[i]), write_char('\n');
    }
    write_flush();
    return 0;
}