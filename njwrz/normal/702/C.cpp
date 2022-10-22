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
int a[100005],b[100005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	m+=2;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,m-1)cin>>b[i];
	b[1]=-2e10;
	b[m]=2e10;
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int ans=0;
	FOR(i,1,n){
		int t=lwb(b+1,b+m+1,a[i])-b;
		gmax(ans,min(abs(b[t]-a[i]),abs(b[t-1]-a[i])));
	}
	cout<<ans;
	RE 0;
}