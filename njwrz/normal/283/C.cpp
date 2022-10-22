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
int n,q,t;
int a[305],p[305];
int dp[100005],to[305],mod=1e9+7,d[100005],in[305];
bool vis[305];
V<int> v[305];
void solve(int x){
	FILL(p,0);
	int len=v[x].size();
	for(int i=len-1;i>=0;i--){
		p[i]=p[i+1]+a[v[x][i]];
	}
	FOR(i,p[0],t)dp[i]=(dp[i]+dp[i-p[0]])%mod;
	FOR(i,1,len-1){
		FILL(d,0);
		for(int j=p[i];j<=t;j++){
			d[j]=(d[j]+dp[j-p[i]]+d[j-p[i]])%mod;
		}
		FOR(j,0,t)dp[j]=d[j];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q>>t;
	FOR(i,1,n)cin>>a[i];
	int x,y;
	FOR(i,1,q){
		cin>>x>>y;
		to[x]=y;in[y]=1;
	}
	int m=0;
	dp[0]=1;
	FOR(i,1,n)if(!vis[i]&&!in[i]){
		++m;
		v[m].PB(i);vis[i]=1;
		int t=i;
		while(to[t]){
			t=to[t];v[m].PB(t);
			if(vis[t]){
				cout<<0;RE 0;
			}
			vis[t]=1;
		}
		reverse(ALL(v[m]));
	}
	FOR(i,1,n){
		if(!vis[i]){
			cout<<0;RE 0;
		}
	}
	FOR(i,1,m){
		solve(i);
	}
	cout<<dp[t];
	RE 0;
}