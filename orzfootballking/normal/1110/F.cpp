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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int N=524288,inf=1e17;
class segtree{
	public:
	int N=524288;
	int add[1048576],now[1048576],l[1048576],r[1048576];
	void build(){
		rep(i,0,N)l[i+N]=r[i+N]=i+1;
		for(int i=N-1;i>=1;i--)l[i]=l[i<<1],r[i]=r[(i<<1)|1];
	}
	void push(int p){
		if(add[p]){
			add[p<<1]+=add[p];now[p<<1]+=add[p];
			add[(p<<1)|1]+=add[p];now[(p<<1)|1]+=add[p];
			add[p]=0;
		}
	}
	void up(int p,int l1,int r1,int x){
		if(l[p]>=l1&&r1>=r[p]){
			now[p]+=x;
			add[p]+=x;
			RE;
		}
		if(l1>r[p]||l[p]>r1)RE;
		push(p);
		up(p<<1,l1,r1,x);
		up((p<<1)|1,l1,r1,x);
		now[p]=min(now[p<<1],now[(p<<1)|1]);
	}
	int get(int p,int l1,int r1){
		if(l[p]>=l1&&r1>=r[p])RE now[p];
		if(l1>r[p]||l[p]>r1)RE inf;
		push(p);
		RE min(get(p<<1,l1,r1),get((p<<1)|1,l1,r1));
	}
}tree;
V<P<int,int> > v[500005];
int n,d[500005],dl[500005],dr[500005],cnt=1,ans[500005];
struct node{
	int id,l,r;
};
V<node> q[500005];
void df(int p){
	dl[p]=cnt++;
	for(auto u:v[p]){
		d[u.F]=d[p]+u.S;
		df(u.F);
	}
	dr[p]=cnt;
}
void dfs(int p){
	for(auto u:q[p]){
		ans[u.id]=tree.get(1,u.l,u.r);
	}
	for(auto u:v[p]){
		tree.up(1,dl[u.F],dr[u.F]-1,-2*u.S);
		tree.up(1,1,n,u.S);
		dfs(u.F);
		tree.up(1,dl[u.F],dr[u.F]-1,2*u.S);
		tree.up(1,1,n,-u.S);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	tree.build();
	int m;
	cin>>n>>m;
	int x,y;
	FOR(i,2,n){
		cin>>x>>y;
		v[x].PB(MP(i,y));
	}
	df(1);
	FOR(i,1,n){
		if(!v[i].size())tree.up(1,i,i,d[i]);else tree.up(1,i,i,inf);
	}
	int p,ui,vi;node cur;
	FOR(i,1,m){
		cin>>p>>ui>>vi;
		cur.id=i;cur.l=ui;cur.r=vi;
		q[p].PB(cur);
	}
	dfs(1);
	FOR(i,1,m)cout<<ans[i]<<'\n';
	RE 0;
}