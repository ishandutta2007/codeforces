#include<bits/stdc++.h>
#define N 1100000
using namespace std;
inline int read() {
    int f;char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while('0' <= ch && ch <= '9') f = (f << 1) + (f << 3) + ch - '0', ch = getchar();
    return f;
}
int n, k, ch[N][26], fail[N], sum[N], ans[N], uid[N], siz[N], cnt, tot, us[N];
int flag[N << 2];
char s[N], opt;
int head[N], last[N];
struct node {
    int to, next;
} e[N];
int edge_id;
void add_edge(int u, int v) {
    ++edge_id;
    if(!head[u]) head[u] = edge_id;
    else e[last[u]].next = edge_id;
    e[edge_id].to = v, last[u] = edge_id;
}
void ins(char *f, int len, int k) {
    int now = 0;
    for(int i = 0; i < len; i++) {
        if(!ch[now][f[i] - 'a']) ch[now][f[i] - 'a'] = ++tot;
        now = ch[now][f[i] - 'a'];
    }
    ans[k] = now;
}
void bfs() {
    queue<int> q;
    for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i++) {
            int v = ch[u][i];
            if(!v) ch[u][i] = ch[fail[u]][i];
            else fail[v] = ch[fail[u]][i], q.push(v);
        }
    }
}
void dfs(int x) {
    uid[x] = ++cnt, siz[x] = 1;
    for(int i = head[x]; i; i = e[i].next) dfs(e[i].to), siz[x] += siz[e[i].to];
}
void pushdown(int x) {
    if(flag[x]) flag[x << 1] += flag[x], flag[x << 1 | 1] += flag[x], flag[x] = 0;
}
void added(int id, int L, int R, int l, int r, int ad) {
    if(l <= L && R <= r) {
        flag[id] += ad;
        return;
    } 
    int mid = (L + R) / 2;
    pushdown(id);
    if(l <= mid) added((id << 1), L, mid, l, r, ad);
    if(r > mid) added((id << 1 | 1), mid + 1, R, l, r, ad);
}
int query(int id, int L, int R, int k) {
    if(L == R) return flag[id];
    pushdown(id);
    int mid = (L + R) / 2;
    if(k <= mid) return query((id << 1), L, mid, k);
    else return query((id << 1 | 1), mid + 1, R, k);
}
void addd(int id, int ad) {
    added(1, 1, cnt, uid[ans[id]], siz[ans[id]] + uid[ans[id]] - 1, ad);
}
void build() {
    for(int i = 1; i <= tot; i++) add_edge(fail[i], i);
    dfs(0);
}
long long getans(char *f, int len) {
    long long Ans = 0;
    int now = 0;
    for(int i = 0; i < len; i++) now = ch[now][f[i] - 'a'], Ans += query(1, 1, cnt, uid[now]);
    return Ans;
}
int main() {
    scanf("%d%d", &k, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        ins(s, strlen(s), i);
    }
    bfs(), build();
    for(int i = 1; i <= n; i++) addd(i, 1), us[i] = 1;
    for(int i = 1; i <= k; i++) {
        opt = getchar();
        while(opt != '+' && opt != '-' && opt != '?') opt = getchar();
        if(opt == '?') scanf("%s", s), printf("%lld\n", getans(s, strlen(s)));
        else {
            int t;
            scanf("%d", &t);
            // t = read();
            // if(t > n) cout << t, exit(0);
            // cout << " t = " << t << endl;
            if(opt == '+' && us[t] == 0) addd(t, 1), us[t] = 1;
            if(opt == '-' && us[t] == 1) addd(t, -1), us[t] = 0;
        }
    }
    return 0;
}// WAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!WAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!