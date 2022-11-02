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
int n,u,r;
int a[35],b[35],k[35],p[35],ans=-1e18;
void dfs(int x,int lst){
//	FOR(i,1,n)cout<<a[i]<<' ';
//	cout<<'\n';
	if((u-x+10)&1){
		int sum=0;
		FOR(i,1,n)sum+=k[i]*a[i];
		gmax(ans,sum);
		if(x==u+1)RE; 
	}
	int t[35];
	FOR(i,1,n)t[i]=a[i];
	if(lst!=1){
		FOR(i,1,n)a[i]=t[i]^b[i];
		dfs(x+1,1);
	}
	FOR(i,1,n)a[i]=t[p[i]]+r;
	dfs(x+1,2);
	FOR(i,1,n)a[i]=t[i];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>u>>r;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,n)cin>>k[i];
	FOR(i,1,n)cin>>p[i];
	dfs(1,2);
	cout<<ans;
	RE 0;
}