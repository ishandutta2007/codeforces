#include<bits/stdc++.h>

using namespace std;

#define N 300'000
#define D 20
#define K 18

int n,fa[N],dep[N],fst[N],lst[N],clk,go[N][K+1];
vector<int> g[N];

struct BIT{
    int f[N][D+1];
    void add(int x,int d,int k){
        for (;x<=n;x+=x&(-x)){
            f[x][d]+=k;
        }
    }
    int qry(int x,int d){
        int sum=0;
        for (;x;x-=x&(-x)){
            for (int j=d;j<=D;++j){
                sum+=f[x][j];
            }
        }
        return sum;
    }
}bit;

void dfs(int u){
    fst[u]=lst[u]=++clk;
    dep[u]=dep[fa[u]]+1;
    go[u][0]=fa[u];
    for (int i=1;i<=K;++i){
        go[u][i]=go[go[u][i-1]][i-1];
    }
    for (int v:g[u]){
        if (v==fa[u]) continue;
        fa[v]=u; dfs(v);
        lst[u]=clk;
    }
}
int lca(int x,int y){
    for (int i=K;i>=0;--i){
        if (dep[go[x][i]]>=dep[y]) x=go[x][i];
        if (dep[go[y][i]]>=dep[x]) y=go[y][i];
    }
    for (int i=K;i>=0;--i){
        if (go[x][i]!=go[y][i]) x=go[x][i],y=go[y][i];
    }
    return x==y?x:fa[x];
}
void add1(int x,int d,int k){
    bit.add(fst[x],d,k);
}
void add2(int x,int d,int k){
    add1(x,d,k);
    if (fa[x]) add1(fa[x],d,-k);
}
void addpath(int x,int z,int d,int k){
    add1(x,d,k); add1(z,d,-k);
}

void add(){
    int x,y,k,d; cin>>x>>y>>k>>d;
    int z=lca(x,y);
    addpath(x,z,d,k);
    addpath(y,z,d,k);
    if (d>0) addpath(x,z,d-1,-k);
    if (d>0) addpath(y,z,d-1,-k);
    for (int i=0;i<=d&&z;++i){
        add2(z,d-i,k);
        if (fa[z]&&d-i-2>=0) add2(z,d-i-2,-k);
        z=fa[z];
    }
}
void qry(){
    int x; cin>>x;
    int ret=0;
    for (int i=0;i<=D&&x;++i){
        ret+=bit.qry(lst[x],i)-bit.qry(fst[x]-1,i);
        x=fa[x];
    }
    cout<<ret<<'\n';
}
int main(){
    cin>>n;
    for (int i=1;i<n;++i){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int m; cin>>m;
    while (m--){
        int op; cin>>op;
        if (op==1) qry();
        else add();
    }
}