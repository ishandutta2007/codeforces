#include <stdio.h>
#define MN 1000000
typedef long long LL;
const int mod=998244353;
int n;
LL fac[MN+5],inv[MN+5],ans=0;
int qpow(int x,int y){
	LL ret=1,bsc=x;
	while(y){
		if(y&1) ret=(ret*bsc)%mod;
		bsc=(bsc*bsc)%mod;
		y>>=1;
	}
	return ret;
}
void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=(inv[i+1]*(i+1))%mod;
}
LL C(int n,int m){
	return (((fac[n]*inv[m])%mod)*inv[n-m])%mod;
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n-1;i++)
		ans=(ans+C(n,i)*fac[n-i])%mod;
	ans=(n*fac[n]-ans)%mod;
	printf("%lld\n",ans);
}