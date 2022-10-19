#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const LL mod=1000000007;
LL n,c,m,phi[N],pre[N],pr[N],ans,vis[N],pw[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld%lld",&n,&c);
	phi[1]=1;
	for (LL i=2;i<=n;++i){
		if (!vis[i]){
			pr[++m]=i;
			phi[i]=i-1;
		}
		for (LL j=1;j<=m;++j){
			if (i*pr[j]>n) break;
			vis[i*pr[j]]=pr[j];
			if (i%pr[j]==0){
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			}
			phi[i*pr[j]]=phi[i]*(pr[j]-1);
		}
		pre[i-1]=(pre[i-2]+phi[i])%mod;
	}
	pw[0]=1; for (LL i=1;i<=n*2;++i) pw[i]=pw[i-1]*c%mod;
	for (LL d=1;d<n;++d){
		upd(ans,pw[d]*pre[n/d-1]);
	}
	for (LL k=n+1;k<=(n-1)*2;++k){
		upd(ans,pw[k-n]*((n-1)*2-k+1));
	}
	for (LL d=1;d<n;++d){
		LL k=(n-1)/d+1;
		if (n/d<k) upd(ans,(pw[d]-pw[k*d-n])*phi[k]);
	}
	ans=ans*inv(pw[n])%mod;
	upd(ans,mod);
	printf("%lld\n",ans);
	
	return 0;
}