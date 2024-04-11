#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 3e5 + 7;
const int M = N * 4;
const int inf = 1e9;
int n, m, endid[N], VAL[N];
int ch[N][26], fa[N], tot = 1;
multiset<int> st[N];
int insert(char *s, int n) {
    int now = 1;
    L(i, 0, n - 1) {
        if(!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot;
        now = ch[now][s[i] - 'a'];
    }
    return now;
}
void bfs() {
    queue<int> q;
    L(i, 0, 25) if(ch[1][i]) fa[ch[1][i]] = 1, q.push(ch[1][i]); else ch[1][i] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        L(i, 0, 25) {
            int v = ch[u][i];
            if(!v) ch[u][i] = ch[fa[u]][i];
            else fa[v] = ch[fa[u]][i], q.push(v);
        }
    }
}
int head[N], edge_id;
struct node { int to, next; } e[N << 1];
void add_edge(int u, int v) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int siz[N], maxto[N], dep[N], uid[N], idtot, heavy[N];
void dfs1(int x) {
    siz[x] = 1;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        fa[v] = x, dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
        if(siz[v] > siz[heavy[x]]) heavy[x] = v;
    }
}
void dfs2(int x) {
    uid[x] = ++idtot;
    if(heavy[x]) maxto[heavy[x]] = maxto[x], dfs2(heavy[x]);
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == heavy[x]) continue;
        maxto[v] = v, dfs2(v);
    }
}
int maxn[M];
void build(int x, int l, int r) { 
    maxn[x] = -1; 
    if(l == r) return; 
    int mid = (l + r) / 2;
    build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
}
void add(int id, int L, int R, int wz, int val) {
    // if(id == 1) cout << wz << " is : " << val << endl;
    if(L == R) return maxn[id] = val, void();
    int mid = (L + R) / 2;
    if(wz <= mid) add(id << 1, L, mid, wz, val);
    else add(id << 1 | 1, mid + 1, R, wz, val);
    maxn[id] = max(maxn[id << 1], maxn[id << 1 | 1]);
}
int query(int id, int L, int R, int l, int r) {
    if(l <= L && R <= r) return maxn[id];
    int mid = (L + R) / 2, res = -1;
    if(l <= mid) res = max(res, query(id << 1, L, mid, l, r));
    if(r > mid) res = max(res, query(id << 1 | 1, mid + 1, R, l, r));
    // if(id == 1) cout << l << " to " << r << "'s max = " << res << endl;
    return res;
}
int get(int x) {
    int res = -1;
    while(x) res = max(res, query(1, 1, tot, uid[maxto[x]], uid[x])), x = fa[maxto[x]];
    return res;
}
char s[N];
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) scanf("%s", s), endid[i] = insert(s, strlen(s));
    bfs();
    L(i, 2, tot) add_edge(fa[i], i);
    dfs1(1), maxto[1] = 1, dfs2(1);
    build(1, 1, tot);
    L(i, 1, n) add(1, 1, tot, uid[endid[i]], 0), st[endid[i]].insert(0);
    while(m--) {
        int opt, x, val;
        scanf("%d", &opt);
        if(opt == 1) {
            scanf("%d%d", &x, &val);
            int now = endid[x];
            st[now].erase(st[now].lower_bound(VAL[x]));
            st[now].insert(val), VAL[x] = val;
            add(1, 1, tot, uid[now], *st[now].rbegin());
        }
        else {
            int maxn = -1, now = 1;
            scanf("%s", s);
            L(i, 0, strlen(s) - 1) now = ch[now][s[i] - 'a'], maxn = max(maxn, get(now)); 
            printf("%d\n", maxn);
        }
    }
	return 0;
}