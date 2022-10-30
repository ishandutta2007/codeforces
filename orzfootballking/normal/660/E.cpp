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
int n,m,p1[1000005],p2[1000005],mod=1e9+7;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int ans=1;
	FOR(i,1,n)ans=ans*m%mod;
	p1[0]=p2[0]=1;
	FOR(i,1,n){
		p1[i]=p1[i-1]*m%mod;
		p2[i]=p2[i-1]*(m+m-1)%mod;
	}
	FOR(i,1,n){
		ans=(ans+p1[n-i+1]*p2[i-1])%mod;
	}
	cout<<ans;
	RE 0;
}