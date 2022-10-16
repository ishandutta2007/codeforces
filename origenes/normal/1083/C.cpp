#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

struct Seg {
    int l, r, lv, rv;
} T[maxn << 2];

vector<int> G[maxn];

int n, q, clk, st[maxn << 1][19], in[maxn], out[maxn], dep[maxn], w[maxn];

void dfs(int u, int p) {
    in[u] = ++clk;
    st[clk][0] = u;
    for (int v : G[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        st[++clk][0] = u;
    }
    out[u] = clk;
}

void rmq_init() {
    FOR(i, 1, clk) FOR(j, 1, 18) {
            st[i][j] = st[i][j - 1];
            int val = i - (1 << j - 1);
            if (val > 0 && dep[st[val][j - 1]] < dep[st[i][j]])
                st[i][j] = st[val][j - 1];
        }
}

inline int rmq(int l, int r) {
    int val = floor(log(r - l + 1) / log(2));
    int u = st[l + (1 << val) - 1][val], v = st[r][val];
    return dep[u] < dep[v] ? u : v;
}

inline int lca(int u, int v) {
    if (in[u] > in[v]) swap(u, v);
    return rmq(in[u], in[v]);
}

inline bool between(int e1, int e2, int m) {
    int a = lca(e1, e2);
    return lca(a, m) == a && (lca(e1, m) == m || lca(e2, m) == m);
}

inline pii get(const int *buff) {
    if (between(buff[0], buff[1], buff[2]) && between(buff[0], buff[1], buff[3])) return mp(buff[0], buff[1]);
    if (between(buff[0], buff[2], buff[1]) && between(buff[0], buff[2], buff[3])) return mp(buff[0], buff[2]);
    if (between(buff[0], buff[3], buff[1]) && between(buff[0], buff[3], buff[2])) return mp(buff[0], buff[3]);
    if (between(buff[1], buff[2], buff[0]) && between(buff[1], buff[2], buff[3])) return mp(buff[1], buff[2]);
    if (between(buff[1], buff[3], buff[0]) && between(buff[1], buff[3], buff[2])) return mp(buff[1], buff[3]);
    if (between(buff[2], buff[3], buff[0]) && between(buff[2], buff[3], buff[1])) return mp(buff[2], buff[3]);
    return mp(-1, -1);
}

void maintain(int o) {
    int lson = o << 1, rson = o << 1 | 1;
    if (T[lson].lv == -1 || T[rson].lv == -1) {
        T[o].lv = T[o].rv = -1;
        return;
    }
    if (T[lson].lv == T[lson].rv) {
        T[o].lv = T[lson].lv;
        T[o].rv = T[rson].lv;
        return;
    }
    int buff[] = {T[lson].lv, T[lson].rv, T[rson].lv, T[rson].rv};
    auto tmp = get(buff);
    T[o].lv = tmp._1;
    T[o].rv = tmp._2;
}

int solve(int o, int &p1, int &p2) {
    if (T[o].lv == -1) {
        if (T[o].l == T[o].r) return T[o].l - 1;
        int flag = solve(o << 1, p1, p2);
        return flag == T[o << 1].r ? solve(o << 1 | 1, p1, p2) : flag;
    }
    int buff[] = {p1, p2, T[o].lv, T[o].rv};
    auto check = get(buff);
    if (check._1 != -1) {
        p1 = check._1, p2 = check._2;
        return T[o].r;
    }
    if (T[o].lv == T[o].rv) return T[o].l - 1;
    int flag = solve(o << 1, p1, p2);
    return flag == T[o << 1].r ? solve(o << 1 | 1, p1, p2) : flag;
}

int query(int o) {
    while (T[o].lv == -1) o <<= 1;
    pii tmp = mp(T[o].lv, T[o].rv);
    return solve(o | 1, tmp._1, tmp._2);
}

void update(int o, int pos, int u) {
    if (T[o].l == T[o].r) {
        T[o].lv = T[o].rv = u;
        return;
    }
    int M = T[o].l + T[o].r >> 1;
    pos <= M ? update(o << 1, pos, u) : update(o << 1 | 1, pos, u);
    maintain(o);
}

void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r;
    T[o].lv = T[o].rv = -1;
    if (l != r) {
        int m = l + r >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
    }
}

int main() {
    scanf("%d", &n);
    build(1, 1, 1 << 18);
    FOR(i, 1, n) {
        scanf("%d", w + i);
        w[i]++;
    }
    FOR(i, 2, n) {
        int d;
        scanf("%d", &d);
        G[i].pb(d);
        G[d].pb(i);
    }
    dfs(1, 0);
    rmq_init();
    FOR(i, 1, n) update(1, w[i], i);
    scanf("%d", &q);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int i, j;
            scanf("%d%d", &i, &j);
            update(1, w[i], j);
            update(1, w[j], i);
            swap(w[i], w[j]);
        } else {
            printf("%d\n", query(1));
        }
    }
}