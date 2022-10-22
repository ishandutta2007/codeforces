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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,m;
int vis[200005];
V<P<int,int> > v[200005];
int col[200005];
P<int,int> p[200005];
int ex[10];
int len=0;
void dfs(int x,int y){
	vis[x]=1;
	for(auto u:v[x])if(u.F!=y&&!col[u.S]){
		if(vis[u.F]){
			col[u.S]=2;ex[++len]=u.S;
		}else{
			col[u.S]=1;
			dfs(u.F,x);
		}
	}
}
V<int> ed;
int getf;
void find(int x,int y,int to){
	if(x==to){
		getf=ed[0];RE;
	}
	for(auto u:v[x])if(col[u.S]==1&&u.F!=y){
		ed.PB(u.S);
		find(u.F,x,to);
		ed.pop_back();
	}
}
void solve(){
	len=0;
	cin>>n>>m;
	FOR(i,1,n)v[i].clear(),vis[i]=0;
	FOR(i,1,m)col[i]=0;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		v[x].PB(MP(y,i));
		v[y].PB(MP(x,i));
		p[i]=MP(x,y);
	}
	dfs(1,-1);
	if(m==n+2&&(p[ex[1]].F^p[ex[1]].S^p[ex[2]].F^p[ex[2]].S^p[ex[3]].F^p[ex[3]].S)==0){
		find(p[ex[1]].F,-1,p[ex[1]].S);
		col[ex[1]]=1;
		col[getf]=2;
	}
	FOR(i,1,m){
		cout<<col[i]-1;
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}