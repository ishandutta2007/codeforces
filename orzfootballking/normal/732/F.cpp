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
int d[400005],low[400005],cnt,sta[400005],top,cnv,id[400005],siz[400005],lst[400005];
V<int> v[400005];
P<int,int> edge[400005];
V<P<int,int>> g[400005];
void dfs(int p,int fa){
	d[p]=++cnt;sta[++top]=p;
	low[p]=d[p];
	for(auto u:v[p])if(u!=fa){
		if(d[u]){
			gmin(low[p],d[u]);
		}else {
			lst[u]=p;dfs(u,p);
			gmin(low[p],low[u]);
		}
	}
	if(low[p]==d[p]){
		cnv++;
		while(1){
			int t=sta[top--];
			id[t]=cnv;siz[cnv]++;
			if(t==p)break;
		}
	}
}
void get(int p,int fa){
	for(auto u:g[p])if(u.F!=fa){
		if(id[edge[u.S].S]!=p){
			swap(edge[u.S].F,edge[u.S].S);
		}
		get(u.F,p);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int x,y;
	cin>>n>>m;
	FOR(i,1,m){
		cin>>x>>y;
		edge[i]=MP(x,y);
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	FOR(i,1,m){
		if(id[edge[i].F]==id[edge[i].S]){
			if(d[edge[i].F]<d[edge[i].S]&&lst[edge[i].S]!=edge[i].F||lst[edge[i].F]==edge[i].S){
				swap(edge[i].F,edge[i].S);
			}
		}else{
			g[id[edge[i].F]].PB(MP(id[edge[i].S],i));
			g[id[edge[i].S]].PB(MP(id[edge[i].F],i));
		}
	}
	int maxi=1;
	FOR(i,2,cnv){
		if(siz[maxi]<siz[i])maxi=i;
	}
	get(maxi,-1);
	cout<<siz[maxi]<<'\n';
	FOR(i,1,m){
		cout<<edge[i].F<<' '<<edge[i].S<<'\n';
	}
	RE 0;
}