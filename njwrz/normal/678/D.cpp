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
int a,b,n,x,mod=1e9+7; 
int _pow(int p,int q){
	if(!q)RE 1;
	int t=_pow(p,q/2);
	if(q&1){
		RE t*t%mod*p%mod;
	}else RE t*t%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>n>>x;
	if(a==1){
		n%=mod;
		cout<<(b*n+x)%mod;
		RE 0;
	}
	int t=1;
	FOR(i,1,n)t=t*a;
	t=_pow(a,n);
	t--;
	t=t*_pow(a-1,mod-2)%mod*b%mod;
	cout<<(t+_pow(a,n)*x)%mod;
	RE 0;
}