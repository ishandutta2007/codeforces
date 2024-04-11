#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
#define inf 10000000000000001ll
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll t[4000001];
ll w[4000001];
ll dist[500001];
void push(int v){
     t[v+v]+=w[v];
     t[v+v+1]+=w[v];
     w[v+v]+=w[v];
     w[v+v+1]+=w[v];
     w[v]=0;
}
void build(int v,int l,int r){
    if (l==r){
        t[v]=dist[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=min(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int L,int R,ll x){
     if (l>R || r<L) return;
     if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
     }
     int m=(l+r)/2;
     push(v);
     upd(v+v,l,m,L,R,x);
     upd(v+v+1,m+1,r,L,R,x);
     t[v]=min(t[v+v],t[v+v+1]);
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return inf;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    push(v);
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
vector<pair<int,pair<int,int> > >query[500001];
int tin[500001];
int tout[500001];
vector<pair<int,ll> >g[500001];
int timer=0;
void dfsinit(int v,ll cur){
     if (g[v].empty()) dist[v]=cur;
     else dist[v]=inf;
     tin[v]=++timer;
     for (auto x:g[v]){
        int to=x.first;
        ll w=x.second*1ll;
        dfsinit(to,cur+w);
     }
     tout[v]=timer;
}
ll ans[500001];
int n,tt;
void dfs(int v){
     for (auto cur:query[v]){
         int l=cur.se.fi;
         int r=cur.se.se;
         int ind=cur.fi;
         ans[ind]=get(1,1,n,l,r);
     }
     for (auto x:g[v]){
         int to=x.fi;
         ll w=x.se*1ll;
         int l=tin[to];
         int r=tout[to];
         upd(1,1,n,1,n,w);
         upd(1,1,n,l,r,-w-w);
         dfs(to);
         upd(1,1,n,1,n,-w);
         upd(1,1,n,l,r,w+w);
     }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>tt;
    for (int i=2;i<=n;i++){
        int p,w;cin>>p>>w;
        g[p].push_back({i,w});
    }
    for (int i=1;i<=tt;i++){
        int v,l,r;cin>>v>>l>>r;
        query[v].push_back({i,{l,r}});
    }
    dfsinit(1,0ll);

    build(1,1,n);
    dfs(1);
    for (int i=1;i<=tt;i++) cout<<ans[i]<<endl;

    return 0;
}