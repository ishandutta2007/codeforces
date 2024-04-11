#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000;
int n, opCnt;
pair<int, int> op[maxN * 20 + 10]; 

struct SplayTree {
    struct Node {
        int fa, ch[2], sz;
        int lv, rv;
    }a[maxN * 2 + 10];
    vector<int> g[maxN + 10];
    int rt, ndCnt;

    void Update(int p) {
        a[p].sz = a[a[p].ch[0]].sz + a[a[p].ch[1]].sz + 1;
        assert(a[a[p].ch[0]].rv == a[a[p].ch[1]].lv);
        a[p].lv = a[a[p].ch[0]].lv;
        a[p].rv = a[a[p].ch[1]].rv;
    }

    void Trans(int f, int d, int p) {
        if (f && d != -1) a[f].ch[d] = p;
        if (p) a[p].fa = f;
    }

    int GetCh(int p) {
        if (a[a[p].fa].ch[0] == p) return 0;
        if (a[a[p].fa].ch[1] == p) return 1;
        return -1;
    }

    void Rotate(int p) {
        op[++opCnt] = make_pair(a[p].lv, a[p].rv);
        int f = a[p].fa, d = GetCh(p), dd = GetCh(f);
        Trans(f, d, a[p].ch[d ^ 1]);
        Trans(a[f].fa, dd, p);
        Trans(p, d ^ 1, f);
        Update(f); Update(p);
    }

    void Splay(int p, int f) {
        while (a[p].fa != f) {
            if (a[a[p].fa].fa != f)
                if (GetCh(p) == GetCh(a[p].fa)) Rotate(a[p].fa);
                else Rotate(p);
            Rotate(p);
        }
    }

    int GetRk(int p) {
        return a[a[p].ch[0]].sz + 1;
    }

    int KthNum(int p, int k) {
        for (;;) {
            int v = a[a[p].ch[0]].sz + 1;
            if (k == v) return p;
            else if (k < v) p = a[p].ch[0];
            else {
                k -= v; p = a[p].ch[1];
            }
        }
    } 

    int Build(int x, int y, int z) {
        int p = ++ndCnt;
        bool fd = 0;
        for (int i = 0, t = 0; i < g[x].size(); ++i) {
            while (t < g[y].size() && g[y][t] < g[x][i]) ++t;
            if (t < g[y].size() && g[y][t] == g[x][i] && g[y][t] != z) {
                assert(!fd);
                fd = 1;
                Trans(p, 0, Build(x, g[x][i], y));
                Trans(p, 1, Build(g[x][i], y, x));
            }
        }
        if (!fd) {
            a[p].lv = x; a[p].rv = y; a[p].sz = 1;
        } else Update(p);
        return p;
    }

    void Init() {
        for (int i = 1; i <= n - 3; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            g[l].push_back(r); g[r].push_back(l);
        }
        for (int i = 1; i < n; ++i) {
            g[i].push_back(i + 1); g[i + 1].push_back(i);
        }
        g[1].push_back(n); g[n].push_back(1);
        rt = ndCnt = 1;
        for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
        Trans(rt, 0, Build(1, 2, 0));
    }
}st, ed;

void Solve(int x, int faX, int y) {
    if (y) {
        int p = st.KthNum(x, ed.GetRk(y));
        st.Splay(p, faX);
        Solve(st.a[p].ch[0], p, ed.a[y].ch[0]);
        Solve(st.a[p].ch[1], p, ed.a[y].ch[1]);
    }
}

int main() {
    scanf("%d", &n);
    st.Init(); ed.Init();
    Solve(st.rt, 0, ed.rt);
    printf("%d\n", opCnt);
    for (int i = 1; i <= opCnt; ++i)
        printf("%d %d\n", op[i].first, op[i].second);
}