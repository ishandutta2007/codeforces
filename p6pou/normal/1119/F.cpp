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

typedef long long i64;
const int MAX_N = 250000 + 5;

namespace TREAP {
    struct Node {
        i64 key, sum;
        int siz, up, son[2];
    } node[MAX_N << 2];

    mt19937 Rand(12345);
    int total, rec[MAX_N << 2], rec_total;
    int gen_node(i64 key) {
        int i = rec_total ? rec[rec_total --] : ++ total;
        node[i].key = node[i].sum = key;
        node[i].siz = 1;
        node[i].up = Rand();
        node[i].son[0] = node[i].son[1] = 0;
        return i;
    }

    struct Treap {
        int root;
        void __update(int i) {
            int ls = node[i].son[0], rs = node[i].son[1];
            node[i].siz = node[ls].siz + node[rs].siz + 1;
            node[i].sum = node[ls].sum + node[rs].sum + node[i].key;
        }
        void __rotate(int &i, int c) {
            int j = node[i].son[c];
            node[i].son[c] = node[j].son[c ^ 1];
            node[j].son[c ^ 1] = i;
            __update(i);
            __update(j);
            i = j;
        }
        void __insert(int &i, i64 key) {
            if (!i) {
                i = gen_node(key);
                return;
            }
            int c = key >= node[i].key;
            __insert(node[i].son[c], key);
            __update(i);
            if (node[i].up < node[node[i].son[c]].up) {
                __rotate(i, c);
            }
        }
        void insert(i64 key) {
            __insert(root, key);
        }
        int __merge(int i, int j) {
            if (!i || !j) {
                return i + j;
            } else if (node[i].up > node[j].up) {
                node[i].son[1] = __merge(node[i].son[1], j);
                __update(i);
                return i;
            } else {
                node[j].son[0] = __merge(i, node[j].son[0]);
                __update(j);
                return j;
            }
        }
        void __erase(int &i, i64 key) {
            if (node[i].key == key) {
                i = __merge(node[i].son[0], node[i].son[1]);
                return;
            }
            int c = key > node[i].key;
            __erase(node[i].son[c], key);
            __update(i);
        }
        void erase(i64 key) {
            __erase(root, key);
        }
        i64 __query(int i, int &k) {
            if (k <= 0) return 0;
            if (node[i].siz <= k) return k -= node[i].siz, node[i].sum;
            i64 res = 0;
            if (k >= 1) res += __query(node[i].son[1], k);
            if (k >= 1) k --, res += node[i].key;
            if (k >= 1) res += __query(node[i].son[0], k);
            return res;
        }
        i64 query(int k) {
            return __query(root, k);
        }
        void __print(int i) {
            if (!i) return;
            __print(node[i].son[0]);
            printf("(key=%lld,sum=%lld,siz=%d)", node[i].key, node[i].sum, node[i].siz);
            __print(node[i].son[1]);
        }
        void print() {
            __print(root);
        }
    };
}

int N;
int elast[MAX_N], deg[MAX_N], ver[MAX_N];
inline bool cmp_by_deg(int i, int j) {
    return deg[i] < deg[j] || deg[i] == deg[j] && i < j;
}
struct Edge {
    int x, y, z, next;
    inline bool operator < (const Edge &b) {
        return x < b.x || x == b.x && deg[y] < deg[b.y];
    }
} e[MAX_N << 1];
int D, vis[MAX_N];
i64 f0[MAX_N], f1[MAX_N];
TREAP::Treap tr[MAX_N];

void dp(int u, int fa) {
    vector<i64> det;
    i64 sum = 0;
    vis[u] = D;
    for (int j = elast[u], v; j; j = e[j].next) {
        if (deg[v = e[j].y] <= D) break;
        if (v == fa) continue;
        dp(v, u);
        sum += f0[v];
        det.push_back(max(f0[v], f1[v] + e[j].z) - f0[v]);
    }
    for (i64 d: det) tr[u].insert(d);
    f0[u] = sum + tr[u].query(D);
    f1[u] = sum + tr[u].query(D - 1);
    // printf("u=%d, sum=%lld, tr[u]={", u, sum);
    // tr[u].print();
    // printf("}, f0=%lld,f1=%lld\n", f0[u], f1[u]);
    for (i64 d: det) tr[u].erase(d);
}
int main() {
    N = read_int();
    i64 sum0 = 0;
    for (int i = 1, j = 1; i < N; i ++) {
        int x = read_int(), y = read_int(), z = read_int();
        // x ++, y ++;
        deg[x] ++, deg[y] ++, sum0 += z;
        e[j ++] = (Edge) {x, y, z, 0};
        e[j ++] = (Edge) {y, x, z, 0};
    }
    for (int i = 1; i <= N; i ++) ver[i] = i;
    sort(ver + 1, ver + 1 + N, cmp_by_deg);
    sort(e + 1, e + 1 + (N - 1 << 1));
    for (int j = 1; j <= N - 1 << 1; j ++) {
        e[j].next = elast[e[j].x], elast[e[j].x] = j;
    }
    int ii = 1;
    vector<i64> Ans;
    Ans.push_back(sum0);
    i64 ans0 = 0;
    for (D = 1; D < N; D ++) {
        // printf("D=%d\n", D);
        for (int u; ii <= N && deg[u = ver[ii]] <= D; ii ++) {
            for (int j = elast[u], v; j; j = e[j].next) {
                if (cmp_by_deg(v = e[j].y, u)) {
                    ans0 += e[j].z;
                } else {
                    tr[e[j].y].insert(e[j].z);
                }
            }
        }
        // printf("ans0=%d\n", ans0);
        // for (int i = 1; i <= N; i ++) {
        //     printf("tr[%d]={", i);
        //     tr[i].print();
        //     printf("}\n");
        // }
        i64 ans = 0;
        for (int i = N, u; i >= 1 && deg[u = ver[i]] > D; i --) {
            if (vis[u] != D) dp(u, 0), ans += f0[u];
        }
        ans = sum0 - ans - ans0;
        Ans.push_back(ans);
    }
    for (int i = 0; i < N; i ++) {
        printf("%lld%c", Ans[i], i + 1 < N ? ' ' : '\n');
    }
    return 0;
}