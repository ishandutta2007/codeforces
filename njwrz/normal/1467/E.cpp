/*

DP





ll int
 dp 










*/
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
int a[200005],n,cnt[200005],in[200005],out[200005],now,d[200005];
V<int> v[200005],g[200005];
void dfs(int x,int fa){
	in[x]=++now;
	for(auto u:v[x]){
		if(u!=fa)d[u]=d[x]+1,dfs(u,x);
	}
	out[x]=now;
} 
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p<=n){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
int get(int x,int c){
	auto r=upb(ALL(g[c]),out[x])-1;
	auto l=lwb(ALL(g[c]),in[x]);
	if(l>r)RE 0;
	RE (r-l+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	V<int> vt;
	FOR(i,1,n)cin>>a[i],vt.PB(a[i]);
	sort(ALL(vt));
	vt.erase(unique(ALL(vt)),vt.end());
	FOR(i,1,n)a[i]=lwb(ALL(vt),a[i])-vt.begin()+1;
	FOR(i,1,n)cnt[a[i]]++;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	FOR(i,1,n)g[a[i]].PB(in[i]);
	FOR(i,1,n)sort(ALL(g[i]));
	FOR(i,1,n){
		int t=get(i,a[i]);t--;
//		cout<<t<<'\n';
		for(auto u:v[i])if(d[u]>d[i]){
			if(get(u,a[i])>0){
				tree.up(1,1);
				tree.up(in[u],-1);
				tree.up(out[u]+1,1);
			}
		}
		if(cnt[a[i]]-t-1>0){
			tree.up(in[i],1);
			tree.up(out[i]+1,-1);
		}
	}
	int ans=0;
	FOR(i,1,n){
		ans+=tree.get(in[i])==0;
	}
	cout<<ans;
	RE 0;
}