#pragma GCC optimize(2)
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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int n,dp[2000005],mod,p2[4000005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	if(y<0)RE 0;
	if(x==2&&y<=4000000)RE p2[y];
	if(!y)RE 1;
	int t=POW(x,y/2);
	if(y&1){
		RE 1ll*t*t%mod*x%mod;
	}else RE 1ll*t*t%mod;
}
int len,tp;
int ad(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	RE x;
}
int get(int l,int r){
	if(l<=n/2&&r>n/2){
		RE ad(ad(dp[l],-dp[n/2+1]+mod),get(n/2+1,r));
	}else if(l<=n/2){
		RE ad(dp[l],-dp[r+1]+mod);
	}else{
		if(r-l+1!=len||r==n){
			RE ad(POW(2,n-l),-((n==r)?0:POW(2,n-r-1))+mod);
		}
		else RE tp;
	}
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	p2[0]=1;
//	io.init();
	cin>>n>>mod;
	FOR(i,1,4000000)p2[i]=ad(p2[i-1],p2[i-1]);
	dp[n/2+1]=POW(2,n-n/2-1);
	int lst=0;
	for(int i=n/2;i>=1;i--){
		len=i;
		tp=ad(POW(2,n-i-i),-POW(2,n-i-i-i)+mod);
		int nowinv=POW(POW(2,i),mod-2);
		for(int j=i+i;j<=n;j+=i){
			add(dp[i],1ll*get(j,min(n,j+i-1))*(j/i-1)%mod);
			tp=1ll*tp*nowinv%mod; 
		}
		int tl=lst;
		lst=dp[i];
		add(dp[i],mod-tl);
		add(dp[i],dp[i+1]);
		if(i==1)cout<<dp[i];
		add(dp[i],dp[i+1]);
	}
//	io.out();
	RE 0;
}