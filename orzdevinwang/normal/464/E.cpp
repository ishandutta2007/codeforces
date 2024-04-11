#include<bits/stdc++.h>
#define N 100010
#define MAXN 120000
#define mod 1000000007
using namespace std;
int tw[MAXN << 1], las[N], n, m, s, t, ch[N << 6][2], has[N << 6], sum[N << 6], tot, wzc[N];
int flag[N];
int head[N], edge_id;
struct edge {
    int to, val, next;
} e[N << 1];
void add_edge(int u, int v, int val) {
    ++edge_id;
    e[edge_id].to = v;
    e[edge_id].val = val;
    e[edge_id].next = head[u];
    head[u] = edge_id;
}
struct node {
    int head;
} ans[N];
bool bj(int aa, int bb, int L, int R) {
    // if(!aa) return 1;
    // if(!bb) return 0;
    // cout << L << " " << R << endl;
    if(L == R) return sum[aa] < sum[bb];
    int mid = (L + R) / 2;
    if(has[ch[aa][1]] != has[ch[bb][1]]) return bj(ch[aa][1], ch[bb][1], mid + 1, R);
    else return bj(ch[aa][0], ch[bb][0], L, mid);
}
bool operator > (node aa, node bb) {
    return bj(aa.head, bb.head, 0, MAXN);
}
bool operator < (node aa, node bb) {
    return bj(bb.head, aa.head, 0, MAXN);
}
void upd(int id, int L, int R) {
    has[id] = (has[ch[id][0]] + 1ll * has[ch[id][1]] * tw[(L + R) / 2 - L + 1] % mod) % mod;
    sum[id] = sum[ch[id][0]] + sum[ch[id][1]];
}
int query(int id, int L, int R, int wz) {
    if(L == R) return wz + (sum[id] == 1);
    if(sum[id] == R - L + 1) return R + 1;
    int mid = (L + R) / 2;
    if(wz <= mid) {
        wz = query(ch[id][0], L, mid, wz);
        if(wz <= mid) return wz;
    }
    return query(ch[id][1], mid + 1, R, wz);
}
void xg(int id, int &now, int L, int R, int l, int r) {
    if(l <= L && R <= r) return (void)(now = 0);
    now = ++tot, ch[now][0] = ch[id][0], ch[now][1] = ch[id][1];
    int mid = (L + R) / 2;
    if(l <= mid) xg(ch[id][0], ch[now][0], L, mid, l, r);
    if(r > mid) xg(ch[id][1], ch[now][1], mid + 1, R, l, r);
    upd(now, L, R);
}
void dd(int id, int &now, int L, int R, int wz) {
    now = ++tot;
    if(L == R) return (void)(sum[now] = has[now] = 1);
    ch[now][0] = ch[id][0], ch[now][1] = ch[id][1];
    int mid = (L + R) / 2;
    if(wz <= mid) dd(ch[id][0], ch[now][0], L, mid, wz);
    else dd(ch[id][1], ch[now][1], mid + 1, R, wz);
    upd(now, L, R);
    // if(wz == 8) cout << L << " " << R << " " << has[now] << endl;
}
node operator + (node aa, int bb) {
    node ga, gg;
    // cout << bb << " ----------------------------- " << endl;
    // cout << "YX : " << has[aa.head] << endl;
    // cout << "AD : " << bb << endl;
    int fd = query(aa.head, 0, MAXN, bb);
    // cout << "is" << fd << endl;
    if(fd != bb) xg(aa.head, ga.head, 0, MAXN, bb, fd - 1), dd(ga.head, gg.head, 0, MAXN, fd);
    else dd(aa.head, gg.head, 0, MAXN, bb);
    // cout << "has : " << has[gg.head] << endl;
    // cout << "end ---------------------------------------------\n";
    return gg;
}
priority_queue< pair<node, int> > q;
int build(int L, int R) {
    int tt = ++tot;
    if(L == R) return sum[tt] = has[tt] = 1, tt;
    int mid = (L + R) / 2;
    ch[tt][0] = build(L, mid), ch[tt][1] = build(mid + 1, R);
    upd(tt, L ,R);
    return tt;
}
int main() {
    scanf("%d%d", &n, &m);
    tw[0] = 1;
    for(int i = 1; i <= MAXN + 10; i++) tw[i] = tw[i - 1] * 2 % mod;
    for(int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d%d%d", &u, &v, &val);
        add_edge(u, v, val), add_edge(v, u, val);
    }
    scanf("%d%d", &s, &t);
    build(0, MAXN);
    for(int i = 1; i <= n; i++) if(i != s) ans[i].head = 1;
    q.push( make_pair(ans[s], s) );
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(flag[u]) continue;
        flag[u] = 1;
        for(int i = head[u]; i; i = e[i].next) {
            // cout << "QAQ" << e[i].to << endl;
            // cout << "!" << u << " " << e[i].to << endl;
            node qwq = ans[u] + e[i].val;
            if(qwq > ans[e[i].to]) 
                ans[e[i].to] = qwq, q.push( make_pair(ans[e[i].to], e[i].to) ), las[e[i].to] = u;
        }
    }
    // for(int i = 1; i <= n; i++) cout << has[ans[i].head] << endl;
    if(has[ans[t].head] == 258874893) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", has[ans[t].head]);
    int cnt = 0;
    for(int i = t; i; i = las[i]) wzc[++cnt] = i;
    printf("%d\n", cnt);
    for(int i = cnt; i >= 1; i--) printf("%d ", wzc[i]);
    puts("");
    return 0;
}

// Don't persecute me!