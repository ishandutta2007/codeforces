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

const int MAX_N = 200000 + 5;

int N, M, ans;
int fath[MAX_N];
struct Edge {
    int x, y, z;
} e[MAX_N];

bool cmp_by_z(const Edge &a, const Edge &b) {
    return a.z > b.z;
}
int get_fath(int u) {
    return fath[u] == u ? u : fath[u] = get_fath(fath[u]);
}

int main() {
    N = read_int(), M = read_int();
    for (int i = 1; i <= M; i ++) {
        e[i].x = read_int(), e[i].y = read_int(), e[i].z = read_int();
    }
    for (int i = 1; i <= N; i ++) {
        fath[i] = i;
    }
    sort(e + 1, e + 1 + M, cmp_by_z);
    for (int i = 1; i <= M; i ++) {
        int x = get_fath(e[i].x), y = get_fath(e[i].y);
        if (x > y) swap(x, y);
        if (x != y) fath[y] = x, ans += e[i].z;
        else if (x != 0) fath[x] = 0, ans += e[i].z;
    }
    printf("%d\n", ans);
    return 0;
}