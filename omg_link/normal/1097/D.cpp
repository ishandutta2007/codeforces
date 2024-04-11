#include <stdio.h>
#define MN 100
#define MK 10000
#define int LL
typedef long long LL;
const int mod=1000000007;
LL n,k,pr[MN+5],pc[MN+5],cnt=0;
LL P=1,Q=1;
LL fP[MN+5][MK+5],div[MN+5][MN+5];
LL qpow(int x,int y){
	LL bsc=x,ret=1;
	while(y){
		if(y&1) ret=(ret*bsc)%mod;
		bsc=(bsc*bsc)%mod;
		y>>=1;
	}
	return ret;
}
void init(){
	for(int i=0;i<=MN;i++)
		for(int j=1;j<=MN;j++)
			div[i][j]=(1ll*i*qpow(j,mod-2))%mod;
}
void dp(LL p,int n,int k){
	for(int i=0;i<=n;i++)
		fP[i][0]=qpow(p%mod,i);
	for(int i=1;i<=k;i++){
		LL pre=0;
		for(int j=0;j<=n;j++){
			pre=(pre+fP[j][i-1])%mod;
			fP[j][i]=(pre*div[1][j+1])%mod;
		}
	}
}
signed main(){
	init();
	scanf("%lld%lld",&n,&k);
	for(LL i=2;i*i<=n;i++){
		if(n%i==0){
			pr[++cnt]=i;
			while(n%i==0)
				n/=i,pc[cnt]++;
		}
	}
	if(n>1) pr[++cnt]=n,pc[cnt]=1;
	for(int i=1;i<=cnt;i++){
		dp(pr[i],pc[i],k);
		P=(P*fP[pc[i]][k])%mod;
	}
	printf("%lld\n",P);
}