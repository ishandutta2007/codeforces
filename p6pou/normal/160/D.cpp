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

const int MAX_N = 100000 + 5;

int N, M;
struct Edge {
    int x, y, z, i;
} e[MAX_N];
int fath[MAX_N], siz[MAX_N], ans[MAX_N];
stack<int> s;

int get_fath(int x) {
    for (; fath[x] != x; x = fath[x]);
    return x;
}
void merge(int x, int y) {
    x = get_fath(x), y = get_fath(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    fath[y] = x, siz[x] += siz[y], s.push(y);
}
void back_to(int ssz) {
    for (int x; (int)s.size() > ssz; s.pop()) x = s.top(), siz[fath[x]] -= siz[x], fath[x] = x;
}
void solve(int l, int r) {
    if (l == r) return (void)(ans[e[l].i] += get_fath(e[l].x) == get_fath(e[l].y));
    int mid = l + r >> 1, ssz = s.size();
    for (int i = mid + 1; i <= r; i ++) merge(e[i].x, e[i].y);
    solve(l, mid), back_to(ssz);
    for (int i = l; i <= mid; i ++) merge(e[i].x, e[i].y);
    solve(mid + 1, r), back_to(ssz);
}
int main() {
    N = read_int(), M = read_int();
    for (int i = 1; i <= M; i ++) e[i].x = read_int(), e[i].y = read_int(), e[i].z = read_int(), e[i].i = i;
    sort(e + 1, e + 1 + M, [] (const Edge &a, const Edge &b) { return a.z < b.z; });
    for (int i = 1; i <= N; i ++) fath[i] = i, siz[i] = 1;
    for (int il = 1, ir; il <= M; il = ir) {
        for (ir = il; ir <= M && e[il].z == e[ir].z; ir ++);
        for (int i = il; i < ir; i ++) ans[e[i].i] += get_fath(e[i].x) == get_fath(e[i].y);
        solve(il, ir - 1);
        for (int i = il; i < ir; i ++) merge(e[i].x, e[i].y);
    }
    const char res[4][20] = { "none\n", "at least one\n", "any\n" };
    for (int i = 1; i <= M; i ++) printf(res[2 - ans[i]]);
    return 0;
}