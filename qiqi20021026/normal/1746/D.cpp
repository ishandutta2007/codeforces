#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define N 300'000

LL f[N][2];
vector<LL> g[N];
vector<LL> dfn;

void dfs(int u){
    dfn.push_back(u);
    for (int v:g[u]){
        dfs(v);
    }
}
void solve(){
    LL n,m; cin>>n>>m;
    vector<LL> fa(n+1),son(n+1),s(n+1),num(n+1);
    // vector<vector<LL>(2)> f(n+1);
    for (LL i=2;i<=n;++i){
        cin>>fa[i];
        g[fa[i]].push_back(i);
        ++son[fa[i]];
    }
    dfn.clear(); dfn.push_back(0); dfs(1);
    for (LL i=1;i<=n;++i){
        cin>>s[i];
    }
    num[1]=m;
    for (LL ii=2;ii<=n;++ii){
        LL i=dfn[ii];
        num[i]=num[fa[i]]/son[fa[i]];
    }
    for (LL ii=n;ii;--ii){
        LL i=dfn[ii];
        f[i][0]=num[i]*s[i];
        if (!son[i]){
            f[i][1]=f[i][0]+s[i];
            continue;
        }
        LL sum=0;
        vector<LL> p;
        for (LL j:g[i]){
            sum+=f[j][0];
            p.push_back(f[j][1]-f[j][0]);
        }
        sort(p.begin(),p.end(),greater<LL>());
        f[i][0]+=sum;
        LL t=num[i]%son[i];
        for (LL j=0;j<t;++j) f[i][0]+=p[j];
        f[i][1]=f[i][0]+s[i]+p[t];
    }
    cout<<f[1][0]<<'\n';
    for (LL i=1;i<=n;++i) g[i].clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--) solve();
}