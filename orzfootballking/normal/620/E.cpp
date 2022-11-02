#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define edge(i,u) for(int i=head[u],v=e[i].v;i;i=e[i].nxt,v =e[i].v)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,a[400005],x,y,L[400005],R[400005],tt,ti[400005],val,anq,tot,er[70];
struct edge{
    int v,nxt;
}e[800005];
int head[400005];
struct node{
    int sum;
    bool tag;
}t[1600005];
void add(int x,int y){
    e[++tot].nxt=head[x];e[tot].v=y;
    head[x]=tot;
}
void put(int k){
    if(t[k].tag){
        t[k].tag=0;
        t[k<<1].sum=t[(k<<1)|1].sum=t[k].sum;
        t[(k<<1)].tag=t[(k<<1)|1].tag=1;
    }
}
int get(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y){
		RE t[k].sum;
	}
    put(k);
    int mid=(l+r)>>1;
    if(y<=mid)RE get((k<<1),l,mid,x,y);
    if(x>mid)RE get((k<<1)|1,mid+1,r,x,y);
    RE get((k<<1),l,mid,x,y)|get((k<<1)|1,mid+1,r,x,y);
}
void dfs(int u,int fa){
    L[u]=++tt;ti[tt]=u;
    edge(i,u){
        if(v==fa)continue;
        dfs(v,u);
    }
    R[u]=tt;
}
void up(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y){
		t[k].sum=er[val];t[k].tag=1;RE;
	}
    put(k);
    int mid=(l+r)>>1;
    if(x<=mid)up((k<<1),l,mid,x,y);
    if(mid<y)up((k<<1)|1,mid+1,r,x,y);
    t[k].sum=t[(k<<1)].sum|t[(k<<1)|1].sum;
}
void build(int k,int l,int r){
    if(l==r){
		t[k].sum=er[a[ti[l]]];RE;
	}
    int mid=(l+r)>>1;
    build((k<<1),l,mid);
    build((k<<1)|1,mid+1,r);
    t[k].sum=t[(k<<1)].sum|t[(k<<1)|1].sum;
}
int ge(int x){
    int re=0;
    while(x)x=x&(x-1),re++;
    RE re;
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    er[0]=1;
    FOR(i,1,60)er[i]=er[i-1]*2;
    cin>>n>>m;
    FOR(i,1,n)cin>>a[i];
    FOR(i,2,n){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs(1,0);
    build(1,1,n);
    FOR(i,1,m){
        cin>>anq;
        if(anq==2){
            cin>>x;
            int ans=get(1,1,n,L[x],R[x]);
            cout<<ge(ans)<<'\n';
        }else{
            cin>>x>>val;
            up(1,1,n,L[x],R[x]);
        }
    }
    RE 0;
}