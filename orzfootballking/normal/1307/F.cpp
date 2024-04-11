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
V<int> v[400005];
int n,k,r;
int vis[400005],to[400005][19],d[400005];
queue<int> q;
struct dsu{
	int fa[400005];
	void init(){
		FOR(i,1,n+n-1)fa[i]=i;
	}
	int getfa(int x){
		RE (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
	}
	void merge(int x,int y){
		x=getfa(x);y=getfa(y);
		if(x!=y){
			fa[x]=y;
		}
	}
}S;
P<int,int> lca(int x,int y){
	int dis=0;
	if(d[x]<d[y])swap(x,y);
	int t=d[x]-d[y];
	rep(i,0,19){
		if(t&(1<<i))x=to[x][i],dis+=(1<<i);
	} 
	if(x==y)RE MP(x,dis);
	for(int i=18;i>=0;i--){
		if(to[x][i]!=to[y][i]){
			x=to[x][i];dis+=(1<<(i+1));
			y=to[y][i];
		}
	}
	dis+=2;
	RE MP(to[x][0],dis);
}
void dfs(int x){
	for(auto u:v[x])if(u!=to[x][0]){
		to[u][0]=x;d[u]=d[x]+1;
		dfs(u);
	}
}
int getto(int x,int y){
	rep(i,0,19){
		if(y&(1<<i)){
			x=to[x][i];
//			cout<<x<<' '<<i<<' ';
		}
	} 
//	cout<<'\n';
	RE x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>r;
	int x,y;S.init();
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(i+n);
		v[i+n].PB(x);
		v[i+n].PB(y);
		v[y].PB(i+n);
	}
	queue<P<int,int> > q;
	int t=k;
	FOR(i,1,r){
		cin>>x;
		q.emplace(MP(x,t));
		vis[x]=1;
	}
	while(!q.empty()){
		P<int,int> cmp=q.front();q.pop();
		if(!cmp.S)continue;
		for(auto u:v[cmp.F]){
			S.merge(u,cmp.F);
			if(vis[u])continue;
			vis[u]=1;
			q.emplace(u,cmp.S-1);
		}
	}
	dfs(1);
	rep(i,1,19){
		FOR(j,1,2*n-1){
			to[j][i]=to[to[j][i-1]][i-1];
		}
	}
	int qu;
	cin>>qu;
	FOR(i,1,qu){
		cin>>x>>y;
		P<int,int> t=lca(x,y);
		if(t.S<=2*k){
			cout<<"YES\n";
		}else{
			int d1=d[x]-d[t.F],d2=d[y]-d[t.F];
			int to1,to2;
			if(d1<k){
				to1=getto(y,t.S-k);
			}else to1=getto(x,k);
			if(d2<k){
				to2=getto(x,t.S-k);
			}else to2=getto(y,k);
			if(S.getfa(to1)==S.getfa(to2)){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
	RE 0;
}