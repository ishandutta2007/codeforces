#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=1e6+9;
int mod,X,inv_k,k;
int in1[N],out1[N],in0[N],out0[N],pw[N],a[N];
int centroid;
ll quick(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
vi g[N];
bool vis[N];
int sz[N],dep[N];
ll tot;
inline void dfs(int u,int f,int n){
	int ok=1;
    sz[u]=1;
    for(auto v:g[u]){
        if(v==f||vis[v])continue;
        dfs(v,u,n);
        if(sz[v]*2>n)ok=0;
        sz[u]+=sz[v];
    }
    if(2*(n-sz[u])>n)ok=0;
    if(ok)centroid=u;
}
int cnt;
pii P1[N],P2[N];
inline void dfs2(const int &u,const int &t,const int &pre,const int &suf,const int &depth){
    vis[u]=1;
    dep[u]=depth;
    P2[cnt]=mp(1ll*(X-suf+mod)*t%mod,u);
    P1[cnt++]=mp(pre,u);
    for(auto v:g[u]){
        if(vis[v])continue;
        dfs2(v,1ll*t*inv_k%mod,(pre+1ll*a[v]*pw[depth+1])%mod,(1ll*suf*k+a[v])%mod,depth+1);
    }
    vis[u]=0;
}
inline void cal(const int &l,const int &r,const int &op){
    sort(P1+l,P1+r);
    sort(P2+l,P2+r);
    int i=l,i0=l,j=l,j0=l;
    for(;i<r;i=i0,j=j0){
        while(i0<r&&P1[i0].fi==P1[i].fi)++i0;
        while(j<r&&P2[j].fi<P1[i].fi)++j;
        j0=j;
        while(j0<r&&P2[j0].fi==P1[i].fi)++j0;
        rep(k,j,j0)in1[P2[k].se]+=op*(i0-i);
        rep(k,i,i0)out1[P1[k].se]+=op*(j0-j);
    }
}
inline void doit(int x,int n){
    dfs(x,0,n);
    x=centroid;
    dep[x]=0;
    cnt=0;
    vis[x]=1;
    for(auto v:g[x]){
        if(vis[v])continue;
        int l=cnt;
        dfs2(v,inv_k,(a[x]+1ll*k*a[v])%mod,a[v],1);
        cal(l,cnt,-1);
    }
    P1[cnt]=mp(a[x],x);
    P2[cnt++]=mp(X,x);
    cal(0,cnt,1);
    for(auto v:g[x]){
        if(vis[v])continue;
        doit(v,sz[v]<sz[x]?sz[v]:n-sz[x]);
    }
}
int main(){
//	freopen("E.in","r",stdin); 
    int n;
    scanf("%d%d%d%d",&n,&mod,&k,&X);
    pw[0]=1;
    rep(i,1,N)pw[i]=1ll*pw[i-1]*k%mod;
    inv_k=quick(k,mod-2);
    rep(i,1,n+1)scanf("%d",&a[i]);
    rep(i,1,n){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    doit(1,n);
    ll ans=0;
    rep(i,1,n+1)in0[i]=n-in1[i],out0[i]=n-out1[i];
    rep(i,1,n+1)ans+=2ll*in0[i]*in1[i]+2ll*out0[i]*out1[i]+1ll*in0[i]*out1[i]+1ll*in1[i]*out0[i];
    ans=1ll*n*n*n-ans/2;
    cout<<ans;
}