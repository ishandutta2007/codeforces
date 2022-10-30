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
void solve(){
	int n,m;char c;
	cin>>n>>m;
	V<V<P<int,int>>> g;
	V<V<bool>> f;  
	V<V<V<P<int,int>>>> v;
	g.resize(n);
	f.resize(n);
	v.resize(n);
	rep(i,0,n)g[i].resize(m),f[i].resize(m),v[i].resize(m);
	rep(i,0,n)rep(j,0,m){
		cin>>c;
		f[i][j]=c-'0';
	}
	rep(i,0,n)rep(j,0,m){
		cin>>c;
		if(c=='R')g[i][j]=MP(0,1),v[i][j+1].PB(MP(i,j));
		if(c=='L')g[i][j]=MP(0,-1),v[i][j-1].PB(MP(i,j));
		if(c=='U')g[i][j]=MP(-1,0),v[i-1][j].PB(MP(i,j));
		if(c=='D')g[i][j]=MP(1,0),v[i+1][j].PB(MP(i,j));
	}
	V<V<int>> deg;
	deg.resize(n);
	queue<P<int,int>> q;
	rep(i,0,n)rep(j,0,m){
		deg[i].PB(v[i][j].size());
		if(!deg[i][j])q.emplace(MP(i,j));
	}
	P<int,int> cur,t;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		t=g[cur.F][cur.S];
		cur.F+=t.F;cur.S+=t.S;
		if(--deg[cur.F][cur.S]==0)
			q.emplace(MP(cur.F,cur.S));
	}
	V<V<int>> d;
	d.resize(n);
	rep(i,0,n)d[i].resize(m,-1);
	int ans1=0,ans2=0;
	rep(i,0,n)rep(j,0,m){
		if(d[i][j]==-1&&deg[i][j]>0){
			deque<P<int,int>> que;
			que.PB(MP(i,j));
			int anst=0;
			d[i][j]=0;
			for(int k=0;k<que.size();k++){
				cur=que[k];anst+=deg[cur.F][cur.S]>0;
				for(auto u:v[cur.F][cur.S])if(d[u.F][u.S]==-1){
					d[u.F][u.S]=d[cur.F][cur.S]+1;
					que.PB(MP(u.F,u.S));
				}
			}
			ans1+=anst;
			V<int> ansv;
			ansv.resize(anst,0);
			for(int k=0;k<que.size();k++){
				if(!ansv[d[que[k].F][que[k].S]%anst]&&!f[que[k].F][que[k].S]){
					ans2++;
					ansv[d[que[k].F][que[k].S]%anst]=1;
				}
			}
		}
	}
	cout<<ans1<<' '<<ans2<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}