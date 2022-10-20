#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
set<pair<int, int>> adj[300300];
ll X;
struct DSU{
    int path[300300], sz[300300];
    ll a[300300];
    void init(int n){
        for (int i=1;i<=n;i++) path[i] = i, sz[i] = 1;
    }
    int find(int x){
        if (x==path[x]) return path[x];
        return path[x]=find(path[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        if (sz[x]>sz[y]) swap(x, y);
        path[x] = y;
        a[y] += a[x]-X;
        sz[y] += sz[x];
        for (auto &v:adj[x]) if (find(v.first)!=y){
            adj[y].insert(v);
        }
    }
}dsu;
struct node{
    int v;
    ll x;
    node(){}
    node(int _v, ll _x): v(_v), x(_x) {}
    bool operator<(const node &N) const{
        return x<N.x;
    }
};

int main(){
    int n, m;
    ll S=0;
    scanf("%d %d %lld", &n, &m, &X);
    for (int i=1;i<=n;i++){
        scanf("%lld", &dsu.a[i]);
        S += dsu.a[i];
    }
    for (int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].insert(make_pair(b, i));
        adj[b].insert(make_pair(a, i));
    }
    if (S<X*(n-1)){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    priority_queue<node> pq;
    dsu.init(n);
    for (int i=1;i<=n;i++) pq.push(node(i, dsu.a[i]));
    vector<int> ans;
    for (int i=1;i<n;i++){
        node cur;
        while(true){
            cur = pq.top(); pq.pop();
            if (dsu.find(cur.v)==cur.v && dsu.a[cur.v]==cur.x) break;
        }
        auto iter = adj[cur.v].begin();
        while(iter!=adj[cur.v].end()){
            int nxt = iter->first;
            if (dsu.find(nxt)!=dsu.find(cur.v)){
                dsu.merge(cur.v, nxt);
                ans.push_back(iter->second);
                pq.push(node(dsu.find(cur.v), dsu.a[dsu.find(cur.v)]));
                break;
            }
            iter = adj[cur.v].erase(iter);
        }
    }
    assert((int)ans.size()==n-1);
    for (auto &x:ans) printf("%d\n", x);
    return 0;
}