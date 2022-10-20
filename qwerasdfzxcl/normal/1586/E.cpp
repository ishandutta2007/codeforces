#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[300300];
struct DSU{
    int path[300300];
    void init(int n) {for (int i=0;i<=n;i++) path[i] = i;}
    int find(int x){
        if (x==path[x]) return x;
        return path[x] = find(path[x]);
    }
    void merge(int s, int v){
        int x = find(s), y = find(v);
        if (x==y) return;
        path[x] = y;
    }
}dsu;
struct LCA{
    int sp[300300][20], dep[300300];
    void init(int s, int pa = -1){
        if (pa!=-1) dep[s] = dep[pa]+1, sp[s][0] = pa;
        for (int j=1;j<20;j++){
            sp[s][j] = sp[sp[s][j-1]][j-1];
        }
        for (auto &v:adj[s]) if (v!=pa) init(v, s);
    }
    void query(int s, int v){
        int x = s, y = v;
        if (dep[s]!=dep[v]){
            if (dep[s]>dep[v]) swap(s, v);
            for (int j=19;j>=0;j--) if (dep[s]<dep[sp[v][j]]) v = sp[v][j];
            v = sp[v][0];
        }
        if (s!=v){
            for (int j=19;j>=0;j--) if (sp[s][j]!=sp[v][j]) s = sp[s][j], v = sp[v][j];
            s = sp[s][0], v = sp[v][0];
        }
        int L = s;

        vector<int> vx, vy;
        while(x!=L) {vx.push_back(x); x = sp[x][0];}
        while(y!=L) {vy.push_back(y); y = sp[y][0];}
        printf("%d\n", (int)vx.size()+(int)vy.size()+1);
        for (int i=0;i<(int)vx.size();i++) printf("%d ", vx[i]);
        printf("%d ", L);
        for (int i=(int)vy.size()-1;i>=0;i--) printf("%d ", vy[i]);
        printf("\n");
    }
}lca;
int cnt[300300];
pair<int, int> a[300300];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    dsu.init(n);
    for (int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (dsu.find(x)==dsu.find(y)) continue;
        dsu.merge(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    lca.init(1);

    int q;
    scanf("%d", &q);
    for (int i=0;i<q;i++){
        scanf("%d %d", &a[i].first, &a[i].second);
        cnt[a[i].first]++;
        cnt[a[i].second]++;
    }

    int ans = 0;
    for (int i=1;i<=n;i++) if (cnt[i]&1) ans++;
    if (!ans){
        printf("YES\n");
        for (int i=0;i<q;i++) lca.query(a[i].first, a[i].second);
    }
    else printf("NO\n%d\n", ans/2);
    return 0;
}