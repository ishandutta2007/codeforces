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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
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
	V<node> g[20005];
	int d[20005];
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
int n,m,g;
int num[20005],a[10005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>g;
	FOR(i,1,n){
		cin>>a[i];
	}
	int ans=0;
	FOR(i,1,n){
		cin>>num[i];
		if(a[i]){
			ans-=num[i];
		}else num[i]=-num[i];
	}
	int S=0,T=n+m+1;
	FOR(i,1,m){
		int now;
		cin>>now;
		if(now){
			cin>>num[n+i];
			int len;
			cin>>len;
			FOR(j,1,len){
				int to;
				cin>>to;mf.add(n+i,to,INF);
			}
			cin>>len;
			if(len==1){
				ans-=g;
				num[n+i]+=g;
			}
		}else{
			cin>>num[n+i];
			ans+=num[n+i];
			int len;
			cin>>len;
			FOR(j,1,len){
				int to;
				cin>>to;mf.add(to,n+i,INF);
			}
			cin>>len;
			if(len==1){
				num[n+i]+=g;
			}
			num[n+i]*=-1;
		}
	}
	FOR(i,1,n+m){
		if(num[i]>=0){
			mf.add(S,i,num[i]);
			ans+=num[i];
		}else{
			mf.add(i,T,-num[i]);
		}
	}
	cout<<ans-mf.get(S,T);
	RE 0;
}