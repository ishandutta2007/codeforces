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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int INF=1e18;
struct max_flow{
	struct node{int to,cap,rev;};
	node edge(int to1,int cap1,int rev1){
		node re;
		re.to=to1;
		re.cap=cap1;
		re.rev=rev1;
		RE re;
	}
	V<node> g[205];
	int d[205],cur[205],vis[205];
	void add(int u,int v,int cap){
		g[u].PB(edge(v,cap,g[v].size()));
		g[v].PB(edge(u,0,g[u].size()-1));
	} 
	void clear(int n){
		FOR(i,0,n)g[i].clear();
	}
	void bfs(int s){
		FILL(d,-1);
		d[s]=0;
		queue<int> q;
		q.emplace(s);
		int cur;
		while(!q.empty()){
			cur=q.front();
			q.pop();
			for(auto &e:g[cur]){
				if(e.cap>0&&d[e.to]<0){
					d[e.to]=d[cur]+1;
					q.emplace(e.to);
				}
			}
		}
	}
	int dfs(int v,int t,int f){
		int dist,re=0;
		if(v==t||!f)RE f;
		rep(i,cur[v],(int)g[v].size()){
			auto &e=g[v][i];
			if(e.cap>0&&d[v]<d[e.to]){
				dist=dfs(e.to,t,min(f,e.cap));
				if(dist>0){
					e.cap-=dist;
					g[e.to][e.rev].cap+=dist;
					re+=dist;
					f-=dist;
					if(!f)break;
				}
			}
			cur[v]++;
		}
		if(!re)d[v]=-1;
		RE re;
	}
	int get(int s,int t){
		int flow=0,f;
		while(1){
			bfs(s);
			if(d[t]<0)break;
			FILL(cur,0);
			f=dfs(s,t,INF);flow+=f;
		}
		FILL(vis,0);
		queue<int> q;
		q.emplace(s);
		vis[s]=1;
		while(!q.empty()){
			int now=q.front();q.pop();
			for(auto u:g[now])if(u.cap&&!vis[u.to]){
				vis[u.to]=1;
				q.emplace(u.to);
			}
		}
		RE flow;
	}
}mf; 
P<int,int> p[1005];
int val[1005];
int n,m;
V<P<int,int> > v[205];
int dis[205][205];
void add(int x,int y,int val){
	v[x].PB(MP(y,val));
	v[y].PB(MP(x,val));
}
void get(V<int> node){
	if(node.size()<=1)RE;
	int S=node[0],T=node[1];
	mf.clear(n);
	FOR(i,1,m)mf.add(p[i].F,p[i].S,val[i]),mf.add(p[i].S,p[i].F,val[i]);
	int val=mf.get(S,T);
	V<int> vl,vr;
	for(auto u:node)if(mf.vis[u])vl.PB(u);else vr.PB(u);
	add(S,T,val);
	get(vl);get(vr);
}
void dfs(int s,int x,int fa,int val){
	if(s!=x){
		dis[s][x]=val;
	}
	for(auto u:v[x])if(u.F!=fa){
		dfs(s,u.F,x,min(val,u.S));
	}
}
int ans;
int a[205];
bool in[205],ok[205];
void get(int x,int y){
	ok[x]=1;
	for(auto u:v[x])if(in[u.F]&&u.F!=y){
		get(u.F,x);
	}
}
void solve(V<int> node,int l,int r){
	if(node.size()==1){
		a[l]=node[0];RE;
	}
	int t1=-1,t2=-1,now=INF;
	for(auto u:node)in[u]=1;
	for(auto u:node)for(auto tu:v[u])if(in[tu.F]){
		if(tu.S<now){
			t1=u;t2=tu.F;now=tu.S;
		}
	}
	ans+=now;
	get(t1,t2);
	V<int> vl,vr;
	for(auto u:node)if(ok[u])vl.PB(u);else vr.PB(u);
	int mid=l+vl.size()-1;
	for(auto u:node)in[u]=ok[u]=0;
	solve(vl,l,mid);solve(vr,mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,m){
		cin>>p[i].F>>p[i].S>>val[i];
	}
	V<int> now;
	FOR(i,1,n)now.PB(i);
	get(now);
	FOR(i,1,n)dfs(i,i,-1,INF);
	solve(now,1,n);
	cout<<ans<<'\n';
	FOR(i,1,n)cout<<a[i]<<' ';
	rep(i,1,n)ans-=dis[a[i]][a[i+1]];
	assert(!ans);
	RE 0;
}