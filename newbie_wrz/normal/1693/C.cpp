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
V<int> v[200005],g[200005];
int siz[200005];
int val[200005],cnt[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	priority_queue<P<int,int>,V<P<int,int> > ,greater<P<int,int> > > q;
	FOR(i,1,n)val[i]=1e18;
	val[n]=0;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		g[y].PB(x);
		v[x].PB(y);
		siz[x]++;
	}
	q.emplace(MP(0,n));
	while(!q.empty()){
		P<int,int> now=q.top();q.pop();
		if(val[now.S]!=now.F)continue;
		for(auto u:g[now.S]){
			++cnt[u];
			if(now.F+siz[u]-cnt[u]+1<val[u]){
				val[u]=now.F+siz[u]-cnt[u]+1;
				q.emplace(MP(val[u],u));
			}
		}
	}
	cout<<val[1];
	RE 0;
}