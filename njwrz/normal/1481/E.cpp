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
int l[500005],r[500005],a[500005],dp[500005],cnt[500005];
bool vis[500005];
V<int> v[500005],g[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		l[i]=1e9;
		r[i]=0;
	}
	FOR(i,1,n){
		cin>>a[i];
		gmin(l[a[i]],i);
		gmax(r[a[i]],i);
		vis[a[i]]=1;
		cnt[a[i]]++;
		g[a[i]].PB(i);
	}
	FOR(i,1,n){
		if(vis[i]){
			v[r[i]].PB(i);
		}
	}
	FOR(i,1,n){
		for(auto u:v[i]){
			gmax(dp[i],dp[l[u]-1]+cnt[u]);
		}
		gmax(dp[i],dp[i-1]);
	}
	int ans=n-dp[n];
	int t=n;
	while(t>1){
		t--;
		if(a[t]!=a[t+1]){
			break;
		}
	}
	gmin(ans,t-dp[t]);
	FOR(i,1,n){
		if(g[i].size()>=2){
			int cntn=0,len=g[i].size();
			for(auto u:g[i]){
				gmin(ans,u-1-dp[u-1]+(n-u+1)-(len-cntn));
				cntn++;
			}
		}
	}
	cout<<ans<<' ';
	RE 0;
}