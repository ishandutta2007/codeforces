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
int n;
int f[1000005],inv[1000005],finv[1000005],mod=1e9+7;
int C(int x,int y){
	if(x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int ans=0;
	for(int i=2;i<=n;i+=2){
		ans=(ans+C(i-1,n-i-1)*f[i]*2)%mod;
		ans=(ans+C(i-1,n-i)*f[i])%mod;
	}
	ans=ans*2%mod;
	cout<<ans;
	RE 0;
}