#include<bits/stdc++.h>

using namespace std;

#define N 1200
#define LL long long

const LL mod=1000000007;
LL n,p1,p2,pa,pb,f[N][N],ans;

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld%lld%lld",&n,&p1,&p2);
	pa=p1*inv(p1+p2)%mod; pb=p2*inv(p1+p2)%mod;
	f[1][0]=1;
	for (LL i=1;i<n;i++)
		for (LL j=0;j<=n;j++){
			if (i+j>=n) ans=(ans+f[i][j]*pb%mod*(i+j))%mod;
			else f[i][j+i]=(f[i][j+i]+f[i][j]*pb)%mod;
			f[i+1][j]=(f[i+1][j]+f[i][j]*pa)%mod;
		}
	for (LL i=0;i<n;i++){
		ans=(ans+f[n][i]*(i+n-1))%mod;
		ans=(ans+f[n][i]*inv(pb))%mod;
	}
	printf("%lld\n",ans);
	
	return 0;
}