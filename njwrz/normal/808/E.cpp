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
int dp[300005];
P<double,int> p[100005];
int a[100005],b[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
		p[i]=MP(1.0*b[i]/a[i],i);
	}
	sort(p+1,p+n+1,greater<P<double,int> >());
	int tot=0;
	FOR(i,1,n){
		int now=p[i].S;
//		cout<<a[now]<<' '<<b[now]<<'\n';
		tot+=a[now];
//		FOR(j,max(a[now],tot-100),tot){
		for(int j=tot;j>=max(a[now],tot-100);j--){
			gmax(dp[j],dp[j-a[now]]+b[now]);
		}
	}
	int ans=0;
	FOR(i,1,min(tot,m))gmax(ans,dp[i]);
	cout<<ans;
	RE 0;
}