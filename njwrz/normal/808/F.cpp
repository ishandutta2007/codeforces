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
	int d[205];
	void clear(){
		FOR(i,0,101)g[i].clear();
	}
	void add(int u,int v,int cap){
		g[u].PB(edge(v,cap,g[v].size()));
		g[v].PB(edge(u,0,g[u].size()-1));
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
		if(v==t)RE f;
		for(auto &e:g[v]){
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
		}
		if(!re)d[v]=-1;
		RE re;
	}
	int get(int s,int t){
		int flow=0,f;
		while(1){
			bfs(s);
			if(d[t]<0)RE flow;
			f=dfs(s,t,INF);flow+=f;
		}
	}
}mf; 
int inf=2147483647;
int p[105],c[105],l[105];
int n,k;
bool ss(int x){
	if(x<2)RE 0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)RE 0;
	}
	RE 1;
}
bool check(int mid){
	mf.clear();
	int t1=-1;
	V<int> v;
	int tot=0;
	FOR(i,1,n){
		if(l[i]<=mid)v.PB(i),tot+=p[i];
	}
	int p1=-1;
	for(auto u:v){
		if(c[u]==1){
			if(p1==-1||p[p1]<p[u]){
				if(p1!=-1)tot-=p[p1];
				p1=u;
			}else{
				tot-=p[u];
			}
		}
	}
	int T=0,S=n+1;
	if(p1!=-1){
		mf.add(S,p1,p[p1]);
		for(auto u:v){
			if(c[u]!=1&&ss(c[u]+1)){
				mf.add(p1,u,inf);
			}
		}
	}
	for(auto u:v){
		if(c[u]==1)continue;
		if(c[u]&1){
			mf.add(S,u,p[u]);
		}else mf.add(u,T,p[u]);
		if(!(c[u]&1))continue;
		for(auto tu:v){
			if(ss(c[u]+c[tu])){
				mf.add(u,tu,inf);
			}
		}
	}
	RE tot-mf.get(S,T)>=k; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>p[i]>>c[i]>>l[i];
	int l=1,r=n,mid,ans=-1;
//	cout<<check(7)<<'\n';
	while(r>=l){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
	RE 0;
}