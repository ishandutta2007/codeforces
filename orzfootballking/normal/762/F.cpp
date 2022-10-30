/*

DP





ll int
 dp 










*/
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
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int mod=1e9+7;
int POW(int x,int y){
	if(!y)RE 1;
	int t=POW(x,y/2);
	if(y&1){
		RE t*t%mod*x%mod;
	}else RE t*t%mod;
}
int inv(int x){
	RE POW(x,mod-2);
}
struct tree{
	V<int> v[1005];
	int ch[1005][1005],siz[1005],n,bit[1005];
	void init(){
		cin>>n;
		rep(i,1,n){
			int x,y;
			cin>>x>>y;
			v[x].PB(y);
			v[y].PB(x);
		}
	}
	void dfs(int x,int fa){
		bit[x]=0;
		siz[x]=0;
		for(auto u:v[x])if(u!=fa){
			ch[x][++siz[x]]=u;bit[x]|=1<<(u-1);
			dfs(u,x);
		}
	}
}S,T;
int dp[1005][1<<12];
int dfs(int fa,int num,int mask){
	if(!num)RE !mask;
	int x=S.ch[fa][num];
	if(dp[x][mask]!=-1)RE dp[x][mask];
	int re=dfs(fa,num-1,mask);
	rep(i,0,T.n)if(mask&(1<<i)){
		re=(re+dfs(fa,num-1,mask^(1<<i))*dfs(x,S.siz[x],T.bit[i+1]))%mod;
	}
	RE dp[x][mask]=re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	S.init();
	T.init();
	S.dfs(1,-1);
	int ans=0,in=0;
	FOR(i,1,T.n){
		FILL(dp,-1);
		T.dfs(i,-1);
		FOR(j,1,S.n)ans=(ans+dfs(j,S.siz[j],T.bit[i]))%mod;
	}
	S=T;
	S.dfs(1,-1);
	FOR(i,1,T.n){
		FILL(dp,-1);
		T.dfs(i,-1);
		in=(in+dfs(1,S.siz[1],T.bit[i]))%mod;
	}
//	cout<<ans<<' '<<in<<' '<<inv(in)<<'\n';
	cout<<ans*inv(in)%mod;
	RE 0;
}