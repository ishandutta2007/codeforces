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
P<P<int,int>,int> p[50];
int len=0;
V<P<int,int> > v[100005];
int n,m;
ll dis[24][100005],dep[100005];
int fa[100005][20],dp[100005];
bool vis[100005];
void dfs(int x,int y){
	vis[x]=1;
	for(auto u:v[x])if(u.F!=y){
		if(vis[u.F]){
			P<int,int> to=MP(x,u.F);
			if(x>u.F){
				swap(to.F,to.S);
			}
			p[++len]=MP(to,u.S);
		}
		else {
			fa[u.F][0]=x;dp[u.F]=dp[x]+1;
			dep[u.F]=dep[x]+u.S;
			dfs(u.F,x);
		}
	}
}
void get(int x){
	int s=p[x].F.S;
	priority_queue<P<ll,int>,V<P<ll,int> > ,greater<P<ll,int> > > q;
	FOR(i,1,n)dis[x][i]=1e18;
	q.emplace(MP(0,s));
	dis[x][s]=0;
	while(!q.empty()){
		P<ll,int> now=q.top();q.pop();
		if(now.F!=dis[x][now.S])continue;
		for(auto u:v[now.S]){
			if(dis[x][u.F]>now.F+u.S){
				dis[x][u.F]=now.F+u.S;
				q.emplace(MP(now.F+u.S,u.F));
			}
		}
	}
}
int getlca(int x,int y){
	if(dp[x]>dp[y])swap(x,y);
	int t=dp[y]-dp[x];
	rep(i,0,18)if(t&(1<<i))y=fa[y][i];
	if(x==y)RE x;
	for(int i=17;i>=0;i--)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];
		y=fa[y][i];
	}
	RE fa[x][0];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	dfs(1,-1);
	sort(p+1,p+len+1);
	len=unique(p+1,p+len+1)-p;
	rep(i,1,18){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	FOR(i,1,len){
		get(i);
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		int mid=getlca(x,y);
		ll ans=dep[x]+dep[y]-2*dep[mid];
		FOR(j,1,len){
			gmin(ans,dis[j][x]+dis[j][y]);
		}
		cout<<ans<<'\n';
	}
	RE 0;
}