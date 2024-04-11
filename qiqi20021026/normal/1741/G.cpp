#include<bits/stdc++.h>

using namespace std;

#define N 600'000

int n,m,p,k;
void solve(){
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for (int i=1;i<=m;++i){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> d(n+1,n+1),vis(n+1);
    d[1]=0;
    for (int i=1;i<=n;++i){
        int u=0;
        for (int j=1;j<=n;++j){
            if (!vis[j]&&d[j]<d[u]) u=j;
        }
        vis[u]=1;
        for (int v:g[u]){
            d[v]=min(d[v],d[u]+1);
        }
    }
    cin>>p;
    vector<int> a(p+1),nocar(p+1);
    for (int i=1;i<=p;++i) cin>>a[i];
    cin>>k;
    vector<vector<int>> key(n+1);
    for (int i=0;i<k;++i){
        int x; cin>>x;
        key[a[x]].push_back(i);
        nocar[x]=1;
    }
    vector<bitset<1<<6>> f(n+1);
    vector<int> id(n+1);
    iota(id.begin(),id.end(),0);
    sort(id.begin()+1,id.begin()+n+1,[&](int x,int y){return d[x]<d[y];});
    f[1][0]=1;
    for (int i=1;i<=n;++i){
        int u=id[i];
        for (int j:key[u]){
            for (int s=0;s<1<<k;++s){
                f[u][s|(1<<j)]=f[u][s|(1<<j)]||f[u][s];
            }
        }
        for (int v:g[u]){
            if (d[v]==d[u]+1) f[v]|=f[u];
        }
    }
    bitset<1<<6> ans; ans[0]=1;
    for (int i=1;i<=p;++i){
        if (nocar[i]) continue;
        for (int s=(1<<k)-1;s>=0;--s){
            for (int t=0;t<1<<k;++t){
                ans[s|t]=ans[s|t]||(ans[s]&&f[a[i]][t]);
            }
        }
    }
    int val=k;
    for (int i=0;i<1<<k;++i){
        if (ans[i]){
            val=min(val,(int)(k-__builtin_popcount(i)));
        }
    }
    cout<<val<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}