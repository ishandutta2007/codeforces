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
inline int read_string(char* s) {
    char* s0 = s;
    for (char ch = read_char(); ch > ' '; ch = read_char()) {
        *s ++ = ch;
    }
    return s - s0;
}

const int MAX_N = 100000 + 5;
const int MAX_L = 600000 + 5;
typedef vector<pair<int,int>> vp32;

int N, M, Q;
int elast[MAX_N], ey[MAX_N << 1], ez[MAX_N << 1], enext[MAX_N << 1];
char buf[MAX_N];
int sql[MAX_N], sqr[MAX_N];
int fath[MAX_N], siz[MAX_N], dep[MAX_N], son[MAX_N], anc[MAX_N];
int chf[MAX_N], spu[MAX_N], spd[MAX_N];
int L, s[MAX_L], rk[MAX_L], sa[MAX_L], wc[MAX_L], wp[MAX_L], rk_[MAX_L];
int lg[MAX_L], h[20][MAX_L], *hei = h[0];
int fro[MAX_L], tr[MAX_L], total_node;
struct Node {
    int ls, rs, cnt;
} node[MAX_L * 20];

void dfs_tcp_1(int u, int fa) {
    siz[u] = 1, fath[u] = fa, dep[u] = dep[fa] + 1;
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fa) {
            chf[v] = ez[j];
            dfs_tcp_1(v, u);
            siz[u] += siz[v];
            son[u] = siz[son[u]] < siz[v] ? v : son[u];
        }
    }
}
void dfs_tcp_2(int u, int anc_) {
    anc[u] = anc_;
    if (u == anc_) {
        spd[u] = L + 1;
        for (int v = u; v; v = son[v]) s[++ L] = chf[v];
        s[++ L] = 1e5 + u;
        for (int i = L - 1; i >= spd[u]; i --) s[++ L] = s[i];
        spu[u] = L;
        s[++ L] = 2e5 + u;
    }
    if (son[u]) dfs_tcp_2(son[u], anc_);
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fath[u] && v != son[u]) {
            dfs_tcp_2(v, v);
        }
    }
}

void get_SA() {
    int i, j, k = 4e5, *rk0 = rk, *rk1 = rk_;
    for (i = 1; i <= L; i ++) wc[s[i]] ++;
    for (i = 1; i <= k; i ++) wc[i] += wc[i - 1];
    for (i = L; i >= 1; i --) sa[wc[s[i]] --] = i;
    for (i = 1; i <= k; i ++) wc[i] = 0;
    for (i = 1, k = 0; i <= L; i ++) rk[sa[i]] = k += s[sa[i]] != s[sa[i - 1]];
    for (int m = 1; m < L && k < L; m <<= 1) {
        for (j = 1; j <= m; j ++) wp[j] = L - m + j;
        for (i = 1; i <= L; i ++) if (sa[i] > m) wp[j ++] = sa[i] - m;
        for (i = 1; i <= L; i ++) wc[rk0[i]] ++;
        for (i = 1; i <= k; i ++) wc[i] += wc[i - 1];
        for (i = L; i >= 1; i --) sa[wc[rk0[wp[i]]] --] = wp[i];
        for (i = 1; i <= k; i ++) wc[i] = 0;
        for (i = 1, k = 0; i <= L; i ++) rk1[sa[i]] = k += rk0[sa[i]] != rk0[sa[i - 1]] || rk0[sa[i] + m] != rk0[sa[i - 1] + m];
        swap(rk0, rk1);
    }
    if (rk0 != rk) for (i = 1; i <= L; i ++) rk[i] = rk0[i];
}
void get_height() {
    for (int i = 1, k = 0; i <= L; i ++) {
        int j = sa[rk[i] - 1];
        for (k -= k > 0; s[i + k] == s[j + k]; k ++);
        hei[rk[i]] = k;
    }
    for (int i = 2; i <= L; i ++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= lg[L]; i ++) {
        int *h0 = h[i], *h1 = h[i - 1], t = 1 << i - 1;
        for (int j = L - (1 << i) + 1; j >= 1; j --) {
            h0[j] = min(h1[j], h1[j + t]);
        }
    }
}
int get_lcp(int p, int q) {
    if (p == q) return L - p + 1;
    p = rk[p], q = rk[q];
    if (p > q) swap(p, q);
    int j = lg[q - p];
    return min(h[j][p + 1], h[j][q - (1 << j) + 1]);
}

#define mid (l + r >> 1)
void segment_add(int &i, int l, int r, int mp) {
    node[++ total_node] = node[i], node[i = total_node].cnt ++;
    if (l != r) mp <= mid ? 
    segment_add(node[i].ls, l, mid, mp) : 
    segment_add(node[i].rs, mid + 1, r, mp);
}
int segment_query(int i0, int i1, int l, int r, int ql, int qr) {
    int res = 0, tmp = node[i1].cnt - node[i0].cnt;
    if (!tmp || ql <= l && r <= qr) return tmp;
    if (ql <= mid) res += segment_query(node[i0].ls, node[i1].ls, l, mid, ql, qr);
    if (mid + 1 <= qr) res += segment_query(node[i0].rs, node[i1].rs, mid + 1, r, ql, qr);
    return res;
}
#undef mid
void segment_build() {
    for (int i = 1; i <= M; i ++) {
        for (int j = sql[i]; j <= sqr[i]; j ++) {
            fro[rk[j]] = i;
        }
    }
    for (int i = 1; i <= L; i ++) {
        tr[i] = tr[i - 1];
        if (fro[i]) segment_add(tr[i], 1, M, fro[i]);
    }
}

vp32 split_channel(int u, int v) {
    vp32 cu, cv;
    while (anc[u] != anc[v]) {
        if (dep[anc[u]] >= dep[anc[v]]) {
            int p = spu[anc[u]], t = dep[u] - dep[anc[u]];
            cu.push_back(make_pair(p - t, p));
            u = fath[anc[u]];
        } else {
            int p = spd[anc[v]], t = dep[v] - dep[anc[v]];
            cv.push_back(make_pair(p, p + t));
            v = fath[anc[v]];
        }
    }
    if (dep[u] > dep[v]) {
        int p = spu[anc[u]], tu = dep[u] - dep[anc[u]], tv = dep[v] - dep[anc[v]];
        cu.push_back(make_pair(p - tu, p - tv - 1));
    } else if (dep[u] < dep[v]) {
        int p = spd[anc[u]], tu = dep[u] - dep[anc[u]], tv = dep[v] - dep[anc[v]];
        cv.push_back(make_pair(p + tu + 1, p + tv));
    }
    cu.insert(cu.end(), cv.rbegin(), cv.rend());
    return cu;
}
void get_rk_range(const vp32 &c, int &pl, int &pr) {
    pl = 1, pr = L;
    for (int i = 0, len = 0; i < (int)c.size(); i ++) {
        int cl = c[i].first, cr = c[i].second;
        // printf("get_rk_range: cl=%d,cr=%d\n", cl, cr);
        for (int j = lg[L]; j >= 0; j --) {
            int p = pl + (1 << j) - 1;
            if (p > pr) continue;
            int q = sa[p] + len, t = get_lcp(cl, q);
            // printf("    pl=%d,j=%d: p=%d,q=%d,t=%d\n", pl, j, p, q, t);
            if (t < cr - cl + 1 && rk[q] < rk[cl]) pl += 1 << j;
        }
        // printf("    pl=%d\n", pl);
        if (pl > pr) return;
        for (int j = lg[L]; j >= 0; j --) {
            int p = pr - (1 << j) + 1;
            if (p < pl) continue;
            int q = sa[p] + len, t = get_lcp(cl, q);
            if (t < cr - cl + 1 && rk[cl] < rk[q]) pr -= 1 << j;
        }
        if (pl > pr) return;
        len += cr - cl + 1;
    }
}

int main() {
    N = read_int(), M = read_int(), Q = read_int();
    for (int i = 1, j = 1; i < N; i ++) {
        int x = read_int(), y = read_int(), z;
        read_string(buf), z = buf[0] - 'a' + 1;
        ey[j] = y, ez[j] = z, enext[j] = elast[x], elast[x] = j ++;
        ey[j] = x, ez[j] = z, enext[j] = elast[y], elast[y] = j ++;
    }
    chf[1] = 27, dfs_tcp_1(1, 0), dfs_tcp_2(1, 1);
    for (int i = 1; i <= M; i ++) {
        int len = read_string(buf);
        sql[i] = L + 1, sqr[i] = L + len;
        for (int j = 0; j < len; j ++) s[++ L] = buf[j] - 'a' + 1;
        s[++ L] = 3e5 + i;
    }
    // for (int i = 1; i <= N; i ++) printf("i=%d, spd=%d, spu=%d\n", i, spd[i], spu[i]);
    // printf("L=%d\n", L);
    // for (int i = !!printf("s  ="); i <= L; i ++) printf("%3d%c", s[i] % 100000 + s[i] / 100000 * 100, i < L ? ' ' : '\n');
    get_SA(), get_height();
    // for (int i = !!printf("rk ="); i <= L; i ++) printf("%3d%c", rk[i], i < L ? ' ' : '\n');
    // for (int i = !!printf("i  ="); i <= L; i ++) printf("%3d%c", i, i < L ? ' ' : '\n');
    // for (int i = !!printf("sa ="); i <= L; i ++) printf("%3d%c", sa[i], i < L ? ' ' : '\n');
    // for (int i = !!printf("hei="); i <= L; i ++) printf("%3d%c", hei[i], i < L ? ' ' : '\n');
    segment_build();
    // for (int i = !!printf("fro="); i <= L; i ++) printf("%3d%c", fro[i], i < L ? ' ' : '\n');
    for (; Q --; ) {
        int u = read_int(), v = read_int(), pl = 0, pr = 0;
        // printf("\nmain: u=%d,v=%d\n", u, v);
        get_rk_range(split_channel(u, v), pl, pr);
        int kl = read_int(), kr = read_int(), res = 0;
        // printf("main:pl=%d,pr=%d, kl=%d,kr=%d\n", pl, pr, kl, kr);
        if (pl <= pr) res = segment_query(tr[pl - 1], tr[pr], 1, M, kl, kr);
        printf("%d\n", res);
    }
    return 0;
}