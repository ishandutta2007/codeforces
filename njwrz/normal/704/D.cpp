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
	struct node{int to,cap,rev,col;};
	node edge(int to1,int cap1,int rev1,int col){
		node re;
		re.to=to1;
		re.cap=cap1;
		re.rev=rev1;
		re.col=col;
		RE re;
	}
	V<node> g[200010];
	int d[200010],cur[200010];
	void add(int u,int v,int cap,int col){
		g[u].PB(edge(v,cap,g[v].size(),col));
		g[v].PB(edge(u,0,g[u].size()-1,col));
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
			if(d[t]<0)RE flow;
			FILL(cur,0);
			f=dfs(s,t,INF);flow+=f;
		}
	}
	int find(int s,int t){
		for(auto u:g[s])if(u.to==t)RE u.cap;
		RE -1;
	}
	void clear(){
		rep(i,0,200010)for(auto &u:g[i])if(u.col==0)u.cap=0;
	}
}mf; 
int tn,q;
map<int,int> mpx,mpy;
P<int,int> p[200005],lx[200005],ly[200005];
int numx[200005],numy[200005];
int sum[200005];
char out[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>tn>>q;
	int r,b;
	cin>>r>>b;
	bool sw=0;
	if(r>b)swap(r,b),sw=1;
	int cntx,cnty;
	cntx=cnty=0;
	FOR(i,1,tn){
		cin>>p[i].F>>p[i].S;
		if(mpx.count(p[i].F))p[i].F=mpx[p[i].F];else p[i].F=mpx[p[i].F]=++cntx;
		if(mpy.count(p[i].S))p[i].S=mpy[p[i].S];else p[i].S=mpy[p[i].S]=++cnty;
		numx[p[i].F]++;numy[p[i].S]++;
	}
	int n=cntx,m=cnty;
	FOR(i,1,n)lx[i]=MP(0,numx[i]);
	FOR(i,1,m)ly[i]=MP(0,numy[i]); 
	FOR(i,1,q){
		int tap,l,d;
		cin>>tap>>l>>d;
		if(tap==1){
			l=mpx[l];
			int tl=(numx[l]-d+1)/2,tr=(numx[l]+d)/2;
			gmax(lx[l].F,tl);gmin(lx[l].S,tr);
		}else{
			l=mpy[l];
			int tl=(numy[l]-d+1)/2,tr=(numy[l]+d)/2;
			gmax(ly[l].F,tl);gmin(ly[l].S,tr);
		}
	}
	FOR(i,1,n)if(lx[i].F>lx[i].S){
		cout<<-1;RE 0;
	}
	FOR(i,1,m)if(ly[i].F>ly[i].S){
		cout<<-1;RE 0;
	}
	int s=0,t=n+m+1,S=t+1,T=S+1;
	FOR(i,1,tn)mf.add(p[i].F,p[i].S+n,1,i);
	FOR(i,1,n){
		mf.add(s,i,lx[i].S-lx[i].F,tn+1);
		sum[s]-=lx[i].F;
		sum[i]+=lx[i].F;
	}
	FOR(i,1,m){
		mf.add(i+n,t,ly[i].S-ly[i].F,tn+1);
		sum[i+n]-=ly[i].F;
		sum[t]+=ly[i].F;
	}
	int ts=0;
	FOR(i,0,n+m+1){
		if(sum[i]<0){
			mf.add(i,T,-sum[i],0);
		}else mf.add(S,i,sum[i],0),ts+=sum[i];
	}
	mf.add(t,s,INF,0);
	if(mf.get(S,T)!=ts){
		cout<<-1;RE 0;
	}else{
		int ans=mf.find(s,t);
		mf.clear();
		int now=ans+mf.get(s,t);
		FOR(i,1,n)for(auto u:mf.g[i])if(u.to>n&&u.to<=n+m&&u.col>=1&&u.col<=tn){
			if(u.cap){
				out[u.col]='b';
			}else out[u.col]='r';
		}
		cout<<now*r+(tn-now)*b<<'\n';
		FOR(i,1,tn){
			if(sw)out[i]^='r'^'b';
			cout<<out[i];
		}
	}
	RE 0;
}