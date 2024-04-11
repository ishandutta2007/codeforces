#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
int n;
P<int,int> p[105]; 
P<int,int> tp[105];
P<int,int> nei[105];
int len[105];
int vis[105],bad[105];
V<int> v[105],id[105];
#define mod 998244353
int cnt2,cnt3;
int tap[105];
bool f;
void dfs(int x){
	if(bad[x])f=0;
	if(vis[x])RE;
	vis[x]=1;
	for(auto u:v[x])dfs(u);
}
int dp[205];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
	}
	FOR(i,1,n){
		int cnt=0;
		FOR(j,1,n)if(i!=j)tp[++cnt]=MP(abs(p[i].F-p[j].F)+abs(p[i].S-p[j].S),j);
		sort(tp+1,tp+n);
		int t=1;
		while(t<=cnt&&tp[t].F==tp[1].F)t++;
		t--;
		FOR(j,1,t)v[i].PB(tp[j].S),v[tp[j].S].PB(i);
		FOR(j,1,t)id[i].PB(tp[j].S);
		id[i].PB(i);
		sort(ALL(id[i]));
	}
	int ans=0;
	FOR(i,1,n)if(!vis[i]){
		for(auto u:id[i]){
			if(id[u]!=id[i]){
				bad[i]=1;
			}
		}
		if(!bad[i])for(auto u:id[i])vis[u]=1;
		tap[i]=id[i].size();
	}
	dp[0]=1;
	FOR(i,1,n){f=1;
		FILL(vis,0);
		dfs(i);
		if(!bad[i]){
			if(!tap[i])continue;
			for(int j=n;j>=0;j--){
				add(dp[j+tap[i]],dp[j]);add(dp[j+1],dp[j]);
				dp[j]=0;
			}
		}else{
			for(int j=n;j>=0;j--){
				add(dp[j+1],dp[j]);
				dp[j]=0;
			}
		}
	}
	int mul=1;
	FOR(i,0,n){
		add(ans,dp[i]*mul%mod);
		mul=mul*(n-i)%mod;
	}
	cout<<ans;
	RE 0;
}