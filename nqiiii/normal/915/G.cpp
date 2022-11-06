#include<cstdio>
typedef long long ll;
const int maxn=2000000,mod=1000000007;
ll add(ll a,ll b){return (a+b)%mod;}
ll dec(ll a,ll b){return (a-b+mod)%mod;}
ll fpow(ll a,ll b){
	ll ans=1; for(;b;b/=2,a=a*a%mod) if(b%2) ans=ans*a%mod;
	return ans;
}
ll f[maxn+10],now,ans; int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		f[i]=add(f[i],dec(fpow(i,n),fpow(i-1,n)));
		now=add(now,f[i]); ans=add(ans,now^i);
		for(int j=i*2;j<=k;j+=i) f[j]=dec(f[j],f[i]);
	}
	printf("%lld",ans); return 0;
}