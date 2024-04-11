#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v[100005];
ll mod=1e9+7;
ll POW(int x){
	if(!x)RE 1;
	ll re=POW(x/2);
	if(x&1){
		RE re*re%mod*2ll%mod;
	}else RE re*re%mod;
}
int d[100005],low[100005],sta[100005],top,cnt,id[100005],siz[100005],cnv;
void dfs(int p,int fa){
	d[p]=++cnt;sta[++top]=p;
	low[p]=d[p];
	for(auto u:v[p])if(u!=fa){
		if(d[u]){
			gmin(low[p],d[u]);
		}else{
			dfs(u,p);
			gmin(low[p],low[u]);
		}
	}
	if(low[p]==d[p]){
		cnv++;
		while(1){
			int t=sta[top--];
			id[t]=cnv;
			siz[cnv]++;
			if(t==p)break;
		}
	}
}
int lst[100005][18],de[100005],cn[100005];
V<int> g[100005];
void get(int p,int fa){
	cn[p]+=siz[p]>1;
	for(auto u:g[p])if(u!=fa){
		lst[u][0]=p;d[u]=d[p]+1;
		cn[u]=cn[p];
		get(u,p);
	}
}
int lca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	int t=d[y]-d[x];
	FOR(i,0,17){
		if(t&(1<<i)){
			y=lst[y][i];
		}
	}
	if(x==y)RE x;
	for(int i=17;i>=0;i--){
		if(lst[x][i]!=lst[y][i]){
			x=lst[x][i];
			y=lst[y][i];
		}
	}
	RE lst[x][0];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	FOR(i,1,n){
		for(auto u:v[i]){
			if(id[u]!=id[i]){
				g[id[u]].PB(id[i]);
				g[id[i]].PB(id[u]);
			}
		}
	}
	FOR(i,1,cnv){
		sort(ALL(g[i]));
		g[i].erase(unique(ALL(g[i])),g[i].end());
	}
	get(1,-1);
	FOR(i,1,17){
		FOR(j,1,n){
			lst[j][i]=lst[lst[j][i-1]][i-1];
		}
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		cin>>x>>y;
		int lc=lca(id[x],id[y]);
		int t=cn[id[x]]+cn[id[y]]-2*cn[lc]+(siz[lc]>1);
		cout<<POW(t)<<'\n';
	}
	RE 0;
}