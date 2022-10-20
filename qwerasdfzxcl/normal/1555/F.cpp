#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct DSU{
    int path[300300];
    void init(int n){
        for (int i=1;i<=n;i++) path[i] = i;
    }
    int find(int s){
        if (s==path[s]) return s;
        return path[s] = find(path[s]);
    }
    void merge(int s, int v){
        int x = find(s), y = find(v);
        if (x==y) return;
        path[x] = y;
    }
}dsu;
vector<pair<int, int>> adj[300300];
vector<int> g[300300];
int dep[300300], pa[300300], pa2[300300], sz[300300], in[300300], inv[300300], top[300300], n;
bool visited[300300], chk[500500];
struct Seg1{
    int tree[600600], sz;
    void init(int n){
        sz = n;
        for (int i=sz;i<(sz*2);i++) tree[i] = pa2[inv[i-sz]];
        for (int i=sz-1;i;i--) tree[i] = tree[i<<1]^tree[i<<1|1];
    }
    int query(int l, int r){
        int ret = 0;
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret ^= tree[l++];
            if (r&1) ret ^= tree[--r];
        }
        return ret;
    }
}tree1;
struct Seg2{
    int tree[1201200], lazy[1201200];
    void propagate(int i, int l, int r){
        tree[i] |= lazy[i];
        if (l!=r){
            lazy[i<<1] |= lazy[i], lazy[i<<1|1] |= lazy[i];
        }
        lazy[i] = 0;
    }
    void update(int i, int l, int r, int s, int e){
        propagate(i, l, r);
        if (r<s || e<l) return;
        if (s<=l && r<=e){
            lazy[i] = 1; propagate(i, l, r); return;
        }
        int m = (l+r)/2;
        update(i<<1, l, m, s, e);
        update(i<<1|1, m+1, r, s, e);
        tree[i] = tree[i<<1]|tree[i<<1|1];
    }
    int query(int i, int l, int r, int s, int e){
        propagate(i, l, r);
        if (r<s || e<l) return 0;
        if (s<=l && r<=e) return tree[i];
        int m = (l+r)/2;
        return query(i<<1, l, m, s, e)|query(i<<1|1, m+1, r, s, e);
    }
}tree2;
struct Query{
    int u, v, x;
    Query(){}
    Query(int _u, int _v, int _x):u(_u), v(_v), x(_x) {}
}query[500500];

void dfs0(int s){
    visited[s] = 1;
    for (auto &v:adj[s]) if (!visited[v.first]){
        g[s].push_back(v.first);
        pa[v.first] = s, pa2[v.first] = v.second;
        dfs0(v.first);
    }
}

void dfs1(int s){
    sz[s] = 1;
    for (auto &v:g[s]){
        dep[v] = dep[s]+1;
        dfs1(v);
        sz[s] += sz[v];
        if (sz[v]>sz[g[s][0]]) swap(v, g[s][0]);
    }
}

int cnt0;
void dfs2(int s){
    in[s] = ++cnt0;
    inv[cnt0] = s;
    for (auto &v:g[s]){
        top[v] = v==g[s][0]?top[s]:v;
        dfs2(v);
    }
}

int _query(int x, int y, int z){
    int val1 = 0, val2 = 0;
    while(top[x]!=top[y]){
        if (dep[top[x]]>dep[top[y]]) swap(x, y);
        val1 ^= tree1.query(in[top[y]], in[y]+1);
        val2 |= tree2.query(1, 1, n, in[top[y]], in[y]);
        y = pa[top[y]];
    }
    if (x!=y){
        if (dep[x]>dep[y]) swap(x, y);
        val1 ^= tree1.query(in[x]+1, in[y]+1);
        val2 |= tree2.query(1, 1, n, in[x]+1, in[y]);
    }
    return ((val1^z) & (!val2));
}

void update(int x, int y){
    while(top[x]!=top[y]){
        if (dep[top[x]]>dep[top[y]]) swap(x, y);
        tree2.update(1, 1, n, in[top[y]], in[y]);
        y = pa[top[y]];
    }
    if (x!=y){
        if (dep[x]>dep[y]) swap(x, y);
        tree2.update(1, 1, n, in[x]+1, in[y]);
    }
}

int main(){
    int q;
    scanf("%d %d", &n, &q);
    dsu.init(n);
    for (int i=0;i<q;i++){
        scanf("%d %d %d", &query[i].u, &query[i].v, &query[i].x);
        if (dsu.find(query[i].u)!=dsu.find(query[i].v)){
            adj[query[i].u].emplace_back(query[i].v, query[i].x);
            adj[query[i].v].emplace_back(query[i].u, query[i].x);
            dsu.merge(query[i].u, query[i].v);
            chk[i] = 1;
        }
    }
    for (int i=1;i<=n;i++) if (!visited[i]){
        dfs0(i); dfs1(i);
        top[i] = i;
        dfs2(i);
    }
    assert(cnt0==n);
    tree1.init(n+1);
    for (int i=0;i<q;i++){
        if (chk[i]) {printf("YES\n"); continue;}
        if (_query(query[i].u, query[i].v, query[i].x)){
            printf("YES\n");
            update(query[i].u, query[i].v);
        }
        else printf("NO\n");
    }
    return 0;
}