#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define ll long long 
using namespace std;
const int N=(int)1e6+9;
const ll mod=(ll)1e9+7;
ll inv[N],jie[N],pre,y[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n<=k+2){
		ll ans=0;
		rep(i,1,n+1)ans+=quick(i,k);
		ans%=mod;
		printf("%lld",ans);
		return 0;
	}
	jie[0]=1;
	inv[0]=1;
	pre=1;
	rep(i,1,k+3){
		y[i]=(y[i-1]+quick(i,k))%mod;
		jie[i]=jie[i-1]*i%mod;
		inv[i]=quick(jie[i],mod-2);
		pre=pre*(n-i)%mod;
	}
//	cout<<pre<<"pre\n"; 
	ll ans=0;
	rep(i,1,k+3){
		int c=((k+2-i)&1)?-1:1;
		ans+=c*pre*quick(n-i,mod-2)%mod*inv[i-1]%mod*inv[k+2-i]%mod*y[i]%mod;
	//	cout<<ans<<"ans\n";
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld",ans);
}