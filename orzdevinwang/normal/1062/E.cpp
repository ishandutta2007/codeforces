#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 2e5 + 7;
const int M = 8e6 + 7;
int n, m, fa[N], siz[N], dep[N], jp[20][N];
int head[N], edge_id;
int hd[N], sum[M], ch[M][2], tot;
struct node { int to, next; } e[N << 1];
void add_edge(int u, int v) { ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; }
void add(int &x, int L, int R, int wz) {
    if(!x) x = ++tot;
    sum[x]++;
    if(L == R) return;
    int mid = (L + R) / 2;
    if(wz <= mid) add(ch[x][0], L, mid, wz);
    else add(ch[x][1], mid + 1, R, wz);
}
int merge(int x, int y) {
    if(!x || !y) return x | y;
    int nw = ++tot;
    sum[nw] = sum[x] + sum[y];
    ch[nw][0] = merge(ch[x][0], ch[y][0]);
    ch[nw][1] = merge(ch[x][1], ch[y][1]);
    return nw;
}
int query(int x, int L, int R, int l, int r) {
    if(!x) return 0;
    if(l <= L && R <= r) return sum[x];
    int mid = (L + R) / 2, res = 0;
    if(l <= mid) res += query(ch[x][0], L, mid, l, r);
    if(r > mid) res += query(ch[x][1], mid + 1, R, l, r);
    return res;
}
void dfs(int x) {
    siz[x] = 1, add(hd[x], 1, n, x);
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to; 
        dep[v] = dep[x] + 1, dfs(v), siz[x] += siz[v];
        // cout << " ? \n";
        hd[x] = merge(hd[x], hd[v]);
        // cout << " ! \n";
    }
}
int get(int x, int l, int r, int y) {
    int nowans = query(hd[x], 1, n, l, r);
    if(nowans > y) return 0;
    if(nowans == y) return x;
    int now = x;
    R(i, 18, 0) if(jp[i][now] && query(hd[jp[i][now]], 1, n, l, r) < y) now = jp[i][now];
    now = fa[now];
    if(query(hd[now], 1, n, l, r) != y) return 0;
    return now;
}
int main() {
    scanf("%d%d", &n, &m);
    L(i, 2, n) scanf("%d", &fa[i]), add_edge(fa[i], i), jp[0][i] = fa[i];
    L(i, 1, 18) L(j, 1, n) jp[i][j] = jp[i - 1][jp[i - 1][j]];
    dfs(1);
    while(m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int resa = get(l + 1, l + 1, r, r - l), resb = get(l, l, r, r - l);
         // 1 : not contain l
        if(dep[resa] >= dep[resb]) printf("%d %d\n", l, dep[resa]);
         // 2 : contain l
        else {
            int L = l, R = r;
            while(L < R) {
                int mid = (L + R) / 2;
                if(query(hd[resb], 1, n, L, mid) != mid - L + 1) R = mid;
                else L = mid + 1;
            }
            printf("%d %d\n", L, dep[resb]);
        }
    }
    return 0;
}