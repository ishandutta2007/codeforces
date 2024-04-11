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
int n;
V<int> v[200005];
V<int> g[200005][2];
bool f;
void dfs(int x,int y){
	int cnt0=0,cnt1=0;
	for(auto u:v[x])if(u!=y)dfs(u,x);
	cnt0=g[x][0].size();cnt1=g[x][1].size();
	int to0,to1;
	to0=to1=v[x].size()/2;
	if(v[x].size()&1)to1++;
	if(cnt0>to0||cnt1>to1)f=0;
	if(y!=-1){
		if(cnt0<to0){
			g[y][0].PB(x);g[x][0].PB(y);
		}else{
			g[y][1].PB(x);g[x][1].PB(y);
		}
	}
}
V<P<int,int> > ans;
int siz[200005];
void add(int x,int y){
	ans.PB(MP(x,y));
	siz[x]--;siz[y]--; 
}
void dfs2(int x,int y,bool f){
	while(siz[x]){
		int t;
		if(siz[x]&1){
			t=g[x][1].back();
			g[x][1].pop_back();
		}else{
			t=g[x][0].back();
			g[x][0].pop_back();
		}
		if(t==y){
			if(!f)continue;
			add(x,y);
		}else{
			if((siz[t]&1)==(siz[x]&1)){
				add(x,t);
				dfs2(t,x,0);
			}else dfs2(t,x,1);
		}
	}
}
void solve(){
	cin>>n;ans.clear();
	FOR(i,1,n)v[i].clear(),g[i][0].clear(),g[i][1].clear(); 
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	f=1;
	dfs(1,-1);
	if(!f){
		cout<<"NO\n";RE;
	}
	FOR(i,1,n)siz[i]=v[i].size();
	dfs2(1,-1,0);
	cout<<"YES\n";
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}