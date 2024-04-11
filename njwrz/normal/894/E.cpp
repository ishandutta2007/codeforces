#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int id[1000005],len,n,sum[1000005],degree[1000005],ans[1000005];
P<P<int,int>,int> p[1000005];
V<int> v[1000005],rv[1000005],s;
V<P<int,int> > sc[1000005]; 
bool vis[1000005];
void add(int x,int y){
	v[x].PB(y);rv[y].PB(x);
}
void dfs(int p){
	vis[p]=1;
	for(auto u:v[p])if(!vis[u]){
		vis[p]=1;
		dfs(u);
	}
	s.PB(p);
}
void rdfs(int p,int color){
	vis[p]=1;id[p]=color;
	for(auto u:rv[p])if(!vis[u]){
		vis[p]=1;
		rdfs(u,color);
	}
}
void scc(){
	FOR(i,1,n)if(!vis[i])dfs(i);
	reverse(ALL(s));FILL(vis,0);
	for(auto u:s)if(!vis[u])rdfs(u,++len);
}
int solve(int x){
	int l=0,r=30000,mid,t;
	while(r>=l){
		mid=(l+r)>>1;
		if((mid*(mid+1)>>1)<=x){
			t=mid;l=mid+1;
		}else r=mid-1;
	}
	RE (t+1)*x+t*(t+1)*(2*t+1)/6-(t+1)*(t+1)*t/2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	FOR(i,1,m){
		cin>>p[i].F.F>>p[i].F.S>>p[i].S;
		add(p[i].F.F,p[i].F.S);
	}
	scc();
	FOR(i,1,m){
		if(id[p[i].F.F]==id[p[i].F.S]){
			sum[id[p[i].F.F]]=sum[id[p[i].F.F]]+solve(p[i].S);
		}else{
			sc[id[p[i].F.F]].PB(MP(id[p[i].F.S],p[i].S));
			degree[id[p[i].F.S]]++;
		}
	}
	int s;
	cin>>s;
	queue<int> q;
	FOR(i,1,len)ans[i]=-1e18;
	ans[id[s]]=0;
	FOR(i,1,len)if(!degree[i])q.emplace(i);
	int cur,maxi=0;
	while(!q.empty()){
		cur=q.front();q.pop();
		ans[cur]=ans[cur]+sum[cur];
		gmax(maxi,ans[cur]);
		for(auto u:sc[cur]){
			degree[u.F]--;gmax(ans[u.F],ans[cur]+u.S);
			if(!degree[u.F])q.emplace(u.F);
		}
	}
	cout<<maxi<<'\n';
	RE 0;
}