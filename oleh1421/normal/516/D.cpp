//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll inf=1000000000001ll;
ll f[N];
ll t[N*4];
ll w[N*4];
int n;
void push(int v){
    t[v+v]+=w[v];
    t[v+v+1]+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,ll x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return -inf;
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int tin[N];
int tout[N];
int timer=0;
vector<pair<int,int> >g[N];
void dfsinit(int v,int pr){
    tin[v]=++timer;
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (to==pr) continue;
        dfsinit(to,v);
        upd(1,1,n,tin[to],tout[to],w);
    }

    tout[v]=timer;
}
void dfs(int v,int pr){
    f[v]=get(1,1,n,1,n);
//    cout<<v<<" "<<f[v]<<endl;
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (to==pr) continue;
        upd(1,1,n,1,n,w);
        upd(1,1,n,tin[to],tout[to],-2ll*w);
        dfs(to,v);
        upd(1,1,n,1,n,-w);
        upd(1,1,n,tin[to],tout[to],2ll*w);
    }
}
int res=0;
ll l;
const int L=20;
int up[N][L+2];
int cnt[N];
int sz[N];
void dfs1(int v,int pr){
    up[v][0]=pr;
    for (int i=1;i<=L;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    int cur=v;
    for (int i=L;i>=0;i--){
        if (up[cur][i] && f[up[cur][i]]+l>=f[v]) cur=up[cur][i];
    }
    cnt[up[cur][0]]--;
    for (auto to:g[v]){
        if (to.first!=pr){
            dfs1(to.first,v);

        }
    }
}
void dfs2(int v,int pr){
    sz[v]=1+cnt[v];
    for (auto to:g[v]){
        if (to.first!=pr){
            dfs2(to.first,v);
            sz[v]+=sz[to.first];
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfsinit(1,0);
    dfs(1,0);
    int root=1;
    for (int i=2;i<=n;i++){
        if (f[i]<f[root]) root=i;
    }
    int q;cin>>q;
    for (;q>0;q--){
        cin>>l;
        memset(cnt,0,sizeof(cnt));
        res=0;
        dfs1(root,0);
        dfs2(root,0);
//        dfs2(root,0,1);
        for (int i=1;i<=n;i++) res=max(res,sz[i]);
        cout<<res<<endl;
    }
    return 0;
}

/*
12
5 9 3
2 1 7
11 7 2
6 5 5
2 5 3
6 7 2
1 4 4
8 5 7
1 3 8
11 12 3
10 8 2
1
7

*/