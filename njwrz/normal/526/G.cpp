#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m,T;
V<P<int,int> > v[100005];
struct sol{
	P<int,int> to[100005];
	int val[100005];
	int tf[100005],root,dis[100005],deep[100005];
	P<int,int> p[100005];
	int fa[100005][20];
	void dfs(int x,int y){
		P<int,int> now=MP(-1,-1);
		for(auto u:v[x])if(u.F!=y){
			dis[u.F]=dis[x]+u.S;
			deep[u.F]=deep[x]+1;
			fa[u.F][0]=x;
			tf[u.F]=u.S;dfs(u.F,x);
			gmax(now,to[u.F]);
		}
		if(now.F!=-1){
			to[x]=MP(now.F+tf[x],now.S);
			val[now.S]+=tf[x];
			val[x]=0;
		}else {
			to[x]=MP(tf[x],x);
			val[x]=tf[x];
		}
	}
	int tim[100005];
	void dfs2(int x,int y){
		for(auto u:v[x])if(u.F!=y){
			dfs2(u.F,x);
			gmin(tim[x],tim[u.F]);
		}
	}
	int ans[100005];
	void pre(){
		dfs(root,-1);
		FOR(i,1,n)p[i]=MP(val[i],i);
		sort(p+1,p+n+1,greater<P<int,int> >());
		FOR(i,1,n)tim[p[i].S]=i,ans[i]=ans[i-1]+p[i].F;
		dfs2(root,-1);
		rep(i,1,19){
			FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	int solve(int x,int k){
		k=min(n,k*2-1);
		if(tim[x]<=k){
			RE ans[k];
		}
		int up=x;
		for(int i=19;i>=0;i--){
			if(fa[up][i]!=0&&tim[fa[up][i]]>k)up=fa[up][i];
		}
		up=fa[up][0];
		int re=ans[k-1]+dis[to[x].S]-dis[up];
		gmax(re,ans[k]-dis[to[up].S]+dis[to[x].S]);
		RE re;
	}
};
sol T1;
sol T2;
int dis[100005];
void getdis(int x){
	priority_queue<P<int,int>,V<P<int,int> >,greater<P<int,int> > > q;
	FILL(dis,-1);
	dis[x]=0;
	q.emplace(MP(0,x));
	while(!q.empty()){
		P<int,int> now=q.top();q.pop();
		if(dis[now.S]!=now.F)continue;
		for(auto u:v[now.S])if(dis[u.F]==-1||dis[u.F]>now.F+u.S){
			dis[u.F]=now.F+u.S;
			q.emplace(MP(dis[u.F],u.F));
		}
	}
}
signed main(){
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;T=1; 
	rep(i,1,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	getdis(1);
	int it=1;
	FOR(i,2,n)if(dis[i]>dis[it])it=i;
	T1.root=it;
	getdis(it);
	it=1;
	FOR(i,2,n)if(dis[i]>dis[it])it=i;
	T2.root=it;
	T1.pre();
	T2.pre();
	int lstans=0;
	FOR(i,1,m){
		int x,k;
		cin>>x>>k;
		x=(x+lstans*T-1)%n+1;
		k=(k+lstans*T-1)%n+1;
		lstans=max(T1.solve(x,k),T2.solve(x,k));
		cout<<lstans<<'\n';
	}
	RE 0;
}