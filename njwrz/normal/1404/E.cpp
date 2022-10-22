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
int INF=1e9;
struct max_flow{
	struct node{int to,cap,rev;};
	node edge(int to1,int cap1,int rev1){
		node re;
		re.to=to1;
		re.cap=cap1;
		re.rev=rev1;
		RE re;
	}
	V<node> g[100005];
	int d[100005];
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
int cnt,id[205][205][2],n,m; //1: 0: 
bool f[205][205];
bool check(int x,int y,int a,int b){
	if(x<1||y<1||x>n||y>m||a<1||b<1||a>n||b>m||!f[x][y]||!f[a][b])RE 0;
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	char c;
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			if(c=='.'){
				f[i][j]=0;
			}else f[i][j]=1,ans++;
		}
	}
	FOR(i,1,n)FOR(j,0,m)id[i][j][0]=++cnt,mf.add(0,cnt,1);
	FOR(i,0,n)FOR(j,1,m)id[i][j][1]=++cnt,mf.add(cnt,100000,1);
	int cnt=0;
	FOR(i,1,n){
		FOR(j,1,m){
			cnt+=check(i,j,i+1,j);
			cnt+=check(i,j,i,j+1);
			if(f[i][j]){
				if(check(i,j,i+1,j)&&check(i,j,i,j+1))mf.add(id[i][j][0],id[i][j][1],INF);
				if(check(i,j,i+1,j)&&check(i,j,i,j-1))mf.add(id[i][j][0],id[i][j-1][1],INF);
				if(check(i,j,i-1,j)&&check(i,j,i,j+1))mf.add(id[i-1][j][0],id[i][j][1],INF);
				if(check(i,j,i-1,j)&&check(i,j,i,j-1))mf.add(id[i-1][j][0],id[i][j-1][1],INF);
			}
		}
	}
	cnt=cnt-mf.get(0,100000);
	cout<<ans-cnt;
	RE 0;
}