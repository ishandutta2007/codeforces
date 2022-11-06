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
const int MAX_SEG = 1 << 19 | 5;

int N, Q;
int elast[MAX_N], ey[MAX_N << 1], enext[MAX_N << 1];
int fath[MAX_N], siz[MAX_N], dep[MAX_N], son[MAX_N], anc[MAX_N];

void dfs_tcp_1(int u, int fa) {
    fath[u] = fa, siz[u] = 1, dep[u] = dep[fa] + 1;
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fa) {
            dfs_tcp_1(v, u);
            siz[u] += siz[v];
            son[u] = siz[son[u]] < siz[v] ? v : son[u];
        }
    }
}
void dfs_tcp_2(int u, int anc_) {
    anc[u] = anc_;
    if (son[u]) dfs_tcp_2(son[u], anc_);
    for (int j = elast[u], v; j; j = enext[j]) {
        if ((v = ey[j]) != fath[u] && v != son[u]) {
            dfs_tcp_2(v, v);
        }
    }
}
int get_lca(int u, int v) {
    while (anc[u] != anc[v]) {
        if (dep[anc[u]] > dep[anc[v]]) {
            u = fath[anc[u]];
        } else {
            v = fath[anc[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}
int get_dis(int u, int v) {
    int w = get_lca(u, v);
    return dep[u] + dep[v] - dep[w] * 2;
}

struct Path {
    int u, v, w;
    Path() : u(0), v(0), w(0) {}
    Path(int u_, int v_) {
        init(u_, v_);
    }
    void init(int u_, int v_) {
        u = u_, v = v_;
        if (u > v) swap(u, v);
        w = !u || !v ? 0 : get_lca(u, v);
    }
    bool operator == (const Path &b) const {
        return u == b.u && v == b.v;
    }
    bool operator != (const Path &b) const {
        return u != b.u || v != b.v;
    }
    bool operator < (const Path &b) const {
        return u < b.u || u == b.u && v < b.v;
    }
};
map<Path, int> pcnt;
map<Path, int> pclk;
int qd[MAX_N];
vector<Path> seg[MAX_SEG];

int get_path_dis(const Path &a, const Path &b) {
    int uu = get_lca(a.u, b.u);
    int uv = get_lca(a.u, b.v);
    int vu = get_lca(a.v, b.u);
    int vv = get_lca(a.v, b.v);
    int s1 = a.w ^ uu ^ vu;
    int s2 = a.w ^ uv ^ vv;
    if (s1 != s2) return 0;
    int t = b.w ^ uu ^ uv;
    return get_dis(s1, t);
}
Path get_path_inter(const Path &a, const Path &b) {
    int uu = get_lca(a.u, b.u);
    int uv = get_lca(a.u, b.v);
    int vu = get_lca(a.v, b.u);
    int vv = get_lca(a.v, b.v);
    int s1 = a.w ^ uu ^ vu;
    int s2 = a.w ^ uv ^ vv;
    if (s1 != s2) return Path(s1, s2);
    int t = b.w ^ uu ^ uv;
    if (s1 == t) return Path(s1, t);
    return Path();
}
struct State {
    int cnt, ty, dis;
    Path P, A, B, C;
    void insert(const Path &D) {
        // printf("insert: cnt=%d,ty=%d,dis=%d, P=(%d,%d),A=(%d,%d),B=(%d,%d),C=(%d,%d)   D=(%d,%d)\n", 
        //     cnt, ty, dis, P.u, P.v, A.u, A.v, B.u, B.v, C.u, C.v, D.u, D.v
        // );
        cnt ++;
        if (cnt == 1) {
            P = A = B = D;
        } else if (ty == 0) {
            Path p = get_path_inter(P, D), t;
            if (p == Path()) {
                ty = 1;
                dis = get_path_dis(P, D);
                int t = get_path_dis(A, D);
                if (dis == t) {
                    B = D;
                } else {
                    t = get_path_dis(B, D);
                    if (dis == t) {
                        A = D;
                    } else {
                        assert(P.u == P.v);
                        assert(C != Path());
                        t = get_path_dis(C, D);
                        assert(dis == t);
                        A = C, B = D;
                    }
                }
            } else if (p != P) {
                Path t = get_path_inter(A, D);
                if (t == p) {
                    P = p, B = D;
                } else {
                    t = get_path_inter(B, D);
                    if (t == p) {
                        P = p, A = D;
                    } else {
                        assert(p.u == p.v);
                        P = p, C = D;
                    }
                }
            }
        } else {
            int ac = get_path_dis(A, D);
            int bc = get_path_dis(B, D);
            if (ac >= bc && ac > dis) {
                dis = ac, B = D;
            } else if (bc >= ac && bc > dis) {
                dis = bc, A = D;
            }
        }
    }
    void query(int &q) {
        if (q != -3) {
            q = cnt <= 1 || q << 1 >= dis ? -1 : -2;
        }
    }
} now;

#define mid (l + r >> 1)
void segment_insert(int i, int l, int r, int ml, int mr, const Path &mp) {
    if (ml <= l && r <= mr) {
        return seg[i].push_back(mp);
    }
    if (ml <= mid) {
        segment_insert(i << 1, l, mid, ml, mr, mp);
    }
    if (mid < mr) {
        segment_insert(i << 1 | 1, mid + 1, r, ml, mr, mp);
    }
}
void segment_solve(int i, int l, int r) {
    State tmp = now;
    for (const Path &p: seg[i]) {
        now.insert(p);
    }
    if (l == r) {
        now.query(qd[l]);
    } else {
        segment_solve(i << 1, l, mid);
        segment_solve(i << 1 | 1, mid + 1, r);
    }
    now = tmp;
}
#undef mid

int main() {
    N = read_int(), Q = read_int();
    for (int i = 1, j = 1; i < N; i ++) {
        int x = read_int(), y = read_int();
        ey[j] = y, enext[j] = elast[x], elast[x] = j ++;
        ey[j] = x, enext[j] = elast[y], elast[y] = j ++;
    }
    dfs_tcp_1(1, 0);
    dfs_tcp_2(1, 1);
    for (int i = 1; i <= Q; i ++) {
        int op = read_int();
        if (op <= 2) {
            qd[i] = -3;
            int u = read_int(), v = read_int();
            Path p(u, v);
            if (op == 1 && ++ pcnt[p] == 1) {
                pclk[p] = i;
            } else if (op == 2 && -- pcnt[p] == 0) {
                segment_insert(1, 1, Q, pclk[p], i, p);
                pclk.erase(p);
            }
        } else {
            qd[i] = read_int();
        }
    }
    for (const auto &p: pclk) {
        segment_insert(1, 1, Q, p.second, Q, p.first);
    }
    segment_solve(1, 1, Q);
    for (int i = 1; i <= Q; i ++) {
        if (qd[i] == -1) {
            printf("Yes\n");
        } else if (qd[i] == -2) {
            printf("No\n");
        }
    }
    return 0;
}