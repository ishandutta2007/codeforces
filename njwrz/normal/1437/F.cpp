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
int inv[5005],finv[5005],f[5005],mod=998244353,n,a[5005],p[5005],dp[5005]; 
void init(){
	inv[1]=1;
	finv[0]=finv[1]=1;
	f[0]=f[1]=1;
	FOR(i,2,5000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int A(int x,int y){
	RE f[x]*finv[x-y]%mod;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;init();
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	FOR(i,1,n){
		rep(j,1,i){
			if(a[j]*2>a[i])break;
			p[i]=j;
		}
	}
	p[0]=-1;
	FOR(i,1,n){
		FOR(j,0,p[i]){
			dp[i]=(dp[i]+dp[j]*A(n-p[j]-2,p[i]-p[j]-1)%mod)%mod;
		}
	}
	if(a[n]>=a[n-1]*2){
		cout<<dp[n];
	}else cout<<0;
	RE 0;
}