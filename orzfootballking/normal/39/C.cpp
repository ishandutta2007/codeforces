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
int low[2005],high[2005],n,dp[4005][4005];
int f[4005][4005];
V<int> v,d[4005];
int dfs(int l,int r){
	if(dp[l][r]!=-1)RE dp[l][r];
	if(l==r)RE dp[l][r]=0;
	int re=0,t=(f[l][r]>0);
	gmax(re,dfs(l+1,r)+t);
	gmax(re,dfs(l,r-1)+t);
	for(auto u:d[r])if(low[u]>l)gmax(re,dfs(l,low[u])+dfs(low[u],r)+t);
	RE dp[l][r]=re;
}
void print(int l,int r){
	if(l==r)RE;
	int t=(f[l][r]>0);
	if(t)cout<<f[l][r]<<' ';
	if(dp[l][r]==dp[l][r-1]+t){
		print(l,r-1);RE;
	}
	if(dp[l][r]==dp[l+1][r]+t){
		print(l+1,r);RE;
	}
	for(auto u:d[r])if(low[u]>l&&dp[l][r]==dp[l][low[u]]+dp[low[u]][r]+t){
		print(l,low[u]);print(low[u],r);RE;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	FOR(i,1,n){
		cin>>x>>y;
		low[i]=x-y;
		high[i]=x+y;
		v.PB(low[i]);
		v.PB(high[i]);
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n){
		low[i]=lower_bound(ALL(v),low[i])-v.begin()+1;
		high[i]=lower_bound(ALL(v),high[i])-v.begin()+1;
		d[high[i]].PB(i);
		f[low[i]][high[i]]=i;
	}
	FILL(dp,-1);
	cout<<dfs(1,v.size())<<'\n';
	print(1,v.size());
	RE 0;
}