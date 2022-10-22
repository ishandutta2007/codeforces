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
#define sz(x) ((int)x.size())
using namespace std;
const int mod=1e9+7; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int n,m;
V<P<int,int> > g[20];
P<int,int> p[20];
int ch[100005];
P<int,int> node[20];
int len,cnt;
struct sol{
	V<int> v[100005];
	int dp[100005][13][2];
	int ans=0;
	int f[1<<13]; 
	int get(){
		rep(mask,0,1<<len)f[mask]=0;
		f[0]=1;
		FOR(i,1,cnt){
			for(int mask=(1<<len)-1;mask>=0;mask--){
				rep(j,0,len)if(!(mask&(1<<j))){
					add(f[mask|(1<<j)],f[mask]*dp[ch[i]][node[j].F][node[j].S]%mod);
				}
			}
		}
		RE f[(1<<len)-1];
	}
	void dfs(int x,int y){
		for(auto u:v[x])if(u!=y)dfs(u,x);
		cnt=0;
		for(auto u:v[x])if(u!=y)ch[++cnt]=u;
		rep(ed,1,m)rep(t,0,2){
			int now;
			if(t==0)now=p[ed].F;else now=p[ed].S;
			len=0;
			for(auto u:g[now])if(u.F!=ed){
				node[len++]=u;
			}
			dp[x][ed][t]=get();
		}
		rep(now,0,m){
			len=0;
			for(auto u:g[now])node[len++]=u;
			add(ans,get());
		}
	}
	int solve(){
		dfs(1,-1);
		RE ans;
	}
}T1,T2;
signed main(){
//	freopen("trtr.in","r",stdin);
//	freopen("trtr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		T1.v[x].PB(y);
		T1.v[y].PB(x);
	}
	cin>>m;
	rep(i,1,m){
		int x,y;
		cin>>x>>y;
		T2.v[x].PB(y);
		T2.v[y].PB(x);
		x--;y--;
		p[i]=MP(x,y);
		g[x].PB(MP(i,1));
		g[y].PB(MP(i,0));
	}
	cout<<T1.solve()*POW(T2.solve(),mod-2)%mod;
	RE 0;
}