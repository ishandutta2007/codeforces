//...
#include <bits/stdc++.h>

#define left_side(_x) (_x * sqrn - sqrn + 1)
#define right_side(_x) (_x * sqrn)

const int N = 1e5 + 620, M = 430;

int n, m, sqrn, a[N], f[N], pos[N];
int block[N], lazy_tag[N];
int block_tot, block_id[N], block_max[N];

unsigned root[M][N], cnt[M][N];

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

/*
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
*/

inline int find(int x) {
    while (x != f[x])
        x = f[x] = f[f[x]];
    return x;
}

inline void upload(int x) {
    const int left = left_side(x), right = right_side(x);
    block_max[x] = 0;
    for (int i = left; i <= right; ++i) {
        block_max[x] = std::max(block_max[x], a[i]);
        if (root[x][a[i]] == 0) {
            pos[i] = a[i];
            root[x][a[i]] = i - left + 1;
            f[i] = i;
        }
        else {
            f[i] = root[x][a[i]] + left - 1;
        }
        ++cnt[x][a[i]];
    }
}

inline void download(int x) {
    int left = left_side(x), right = right_side(x);
    for (int i = left; i <= right; ++i) {
        a[i] = pos[find(i)];
        root[x][a[i]] = cnt[x][a[i]] = 0;
        a[i] -= lazy_tag[x];
    }
    lazy_tag[x] = 0;
    for (int i = left; i <= right; ++i)
        f[i] = 0;
}

inline void Union(int x, int u, int v) {
    int left = left_side(x);
    if (root[x][v] == 0) {
        root[x][v] = root[x][u];
        pos[root[x][u] + left - 1] = v;
    }
    else
        f[root[x][u] + left - 1] = root[x][v] + left - 1;
    cnt[x][v] += cnt[x][u];
    cnt[x][u] = root[x][u] = 0;
}

inline void block_modify(int x, int v) {
    if ((v << 1) <= block_max[x] - lazy_tag[x]) {
        for (int i = lazy_tag[x] + 1; i <= lazy_tag[x] + v; ++i)
            if (root[x][i]) Union(x, i, i + v);
        lazy_tag[x] += v;
    }
    else {
        for (int i = block_max[x]; i > lazy_tag[x] + v; --i)
            if (root[x][i]) Union(x, i, i - v);
        block_max[x] = std::min(block_max[x], lazy_tag[x] + v);
    }
}

inline void modify(int l, int r, int x) {
    int id_l = block_id[l], id_r = block_id[r];
    if (id_l == id_r) {
        download(id_l);
        for (int i = l; i <= r; ++i) if (a[i] > x) a[i] -= x;
        upload(id_l);
    }
    else {
        int bl_r = right_side(id_l), br_l = left_side(id_r);
        download(id_l);
        download(id_r);
        for (int i = l; i <= bl_r; ++i) if (a[i] > x) a[i] -= x;
        for (int i = br_l; i <= r; ++i) if (a[i] > x) a[i] -= x;
        for (int i = id_l + 1; i < id_r; ++i)
            block_modify(i, x);
        upload(id_l);
        upload(id_r);
    }
}

inline int query(int l, int r, int x) {
    int id_l = block_id[l], id_r = block_id[r], ans = 0;
    if (id_l == id_r) {
        for (int i = l; i <= r; ++i)
            if (pos[find(i)] - lazy_tag[id_l] == x) ++ans;
    }
    else {
        int bl_r = right_side(id_l), br_l = left_side(id_r);
        for (int i = l; i <= bl_r; ++i) if (pos[find(i)] - lazy_tag[id_l] == x) ++ans;
        for (int i = br_l; i <= r; ++i) if (pos[find(i)] - lazy_tag[id_r] == x) ++ans;
        for (int i = id_l + 1; i < id_r; ++i) {
            if (x + lazy_tag[i] < N)
                ans += cnt[i][x + lazy_tag[i]];
        }
    }
    return ans;
}

int main() {
    n = read(), m = read(), sqrn = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        block_id[i] = block_tot = (i - 1) / sqrn + 1;
    }
    for (int i = 1; i <= block_tot; ++i)
        upload(i);
    while (m--) {
        int opt = read(), l = read(), r = read(), x = read();
        if (opt == 1) modify(l, r, x);
        else printf("%d\n", query(l, r, x));
    }
    return 0;
}