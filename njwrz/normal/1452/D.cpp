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
const int mod=998244353;
int sum[2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	sum[0]=1;
	rep(i,1,n){
		if(i&1)sum[1]=(sum[0]+sum[1])%mod;
		else sum[0]=(sum[0]+sum[1])%mod;
	}
	int ans=sum[!(n&1)];
	FOR(i,1,n){
		ans=ans*((mod+1)/2)%mod;
	}
	cout<<ans;
	RE 0;
}