#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<P<int,int> > b[5005];
int f[5005],l[5005],r[5005],d[5005],de[5005],id[5005];
int n,m,fa[5005];
void dfs(int p,int last){
    fa[p]=last;de[p]=de[last]+1;
    for(int i=0;i<b[p].size();i++){
        int v=b[p][i].first;
        if(v==last)continue;
        dfs(v,p);id[v]=b[p][i].second;
    }
}
bool get(int u,int v,int w){
    int re=1000000000;
    if(de[u]<de[v])swap(u,v);
    while(de[u]>de[v]){
        re=min(f[id[u]],re);
        if(re<w)RE 0;
        u=fa[u];
    }
    while(u!=v){
        re=min(f[id[u]],re);
        re=min(f[id[v]],re);
        if(re<w)RE 0;
        u=fa[u],
        v=fa[v];
    }
    RE (w==re);
}
void up(int u,int v,int w){
    if(de[u]<de[v])swap(u,v);
    while(de[u]>de[v]) {
        f[id[u]]=max(f[id[u]],w);u=fa[u];
    }
    while(u!=v){
        f[id[u]]=max(f[id[u]],w),
    	f[id[v]]=max(f[id[v]],w),
        u=fa[u],v=fa[v];
    }
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;int x,y;
    FOR(i,1,n-1){
        cin>>x>>y;
        b[x].PB(MP(y,i)),
        b[y].PB(MP(x,i));
        f[i]=1;
    }
    dfs(1,0);
    cin>>m;
	int u,v,w;
    FOR(i,1,m){
        cin>>u>>v>>w;
        up(u,v,w);
        l[i]=u;r[i]=v;d[i]=w;
    }
    FOR(i,1,m){
        if(!get(l[i],r[i],d[i])){
        	cout<<-1;RE 0;
		}
    }
    FOR(i,1,n-1)cout<<f[i]<<' ';
    return 0;
}