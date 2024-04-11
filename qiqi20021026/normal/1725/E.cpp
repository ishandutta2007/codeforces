#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const LL mod=998244353,K=19;
LL n,a[N],sz[N],dfn[N],dep[N],go[N][K+1],clk,ans,vis[N];
vector<LL> pr,g[N],e[N],vec[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

void init(LL n){
    for (LL i=2;i<=n;++i){
        if (!vis[i]){
            vis[i]=i;
            pr.push_back(i);
        }
        for (LL j:pr){
            if (i*j>n) break;
            vis[i*j]=j;
            if (i%j==0) break;
        }
    }
}

LL lca(LL x,LL y){
    for (LL i=K;i>=0;--i){
        if (dep[go[x][i]]>=dep[y]) x=go[x][i];
        if (dep[go[y][i]]>=dep[x]) y=go[y][i];
    }
    for (LL i=K;i>=0;--i){
        if (go[x][i]!=go[y][i]) x=go[x][i],y=go[y][i];
    }
    return x==y?x:go[x][0];
}

void dfs(LL u,LL fa){
    dep[u]=dep[fa]+1;
    dfn[u]=++clk;
    go[u][0]=fa;
    for (LL i=1;i<=K;++i) go[u][i]=go[go[u][i-1]][i-1];
    for (LL v:g[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
}

LL sum(LL x,LL y){
    return (x*(x-1)
    /2*y+x*y*(y-1)/2)%mod;
}
void calc(LL u,LL fa,LL p,LL tot){
    sz[u]=a[u]%p==0;
    for (LL v:e[u]){
        calc(v,u,p,tot);
        sz[u]+=sz[v];
    }
    upd(ans,sum(sz[u],tot-sz[u])*(dep[u]-dep[fa]));
    e[u].clear();
}
LL stk[N];
void add(LL x,LL y){e[x].push_back(y);}
void solve(LL p){
    auto &q=vec[p];
    sort(q.begin(),q.end(),[=](LL x,LL y){return dfn[x]<dfn[y];});
    LL tp=1; stk[tp]=1;
    for (auto v:q){
        if (v==stk[tp]) continue;
        LL ance=lca(stk[tp],v);
        while (dep[ance]<dep[stk[tp-1]]){
            add(stk[tp-1],stk[tp]);
            --tp;
        }
        if (dep[ance]<dep[stk[tp]]) add(ance,stk[tp--]);
        if (stk[tp]!=ance) stk[++tp]=ance;
        stk[++tp]=v;
    }
    while (tp--) add(stk[tp],stk[tp+1]);
    calc(1,0,p,q.size());
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init(200000);
    cin>>n;
    for (LL i=1;i<=n;++i) cin>>a[i];
    for (LL i=1;i<n;++i){
        LL x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (LL i=1;i<=n;++i){
        LL x=a[i];
        while (x>1){
            LL d=vis[x];
            vec[d].push_back(i);
            while (x%d==0) x/=d;
        }
    }
    dfs(1,0);
    for (LL i=2;i<=200000;++i){
        if (vis[i]==i) solve(i);
    }
    cout<<ans<<'\n';

    return 0;
}