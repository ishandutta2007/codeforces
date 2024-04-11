#include <stdio.h>
#define MN 1000000
typedef long long ll;
const int mod = 1000000007;

int fac[MN+5],inv[MN+5];

int qpow(int bsc,int y){
	int ret = 1;
	while(y){
		if(y&1) ret = (ll)ret*bsc%mod;
		bsc = (ll)bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}

void init(){
	fac[0] = 1;
	for(int i=1;i<=MN;i++)
		fac[i] = (ll)fac[i-1]*i%mod;
	inv[MN] = qpow(fac[MN],mod-2);
	for(int i=MN-1;i>=0;i--)
		inv[i] = (ll)inv[i+1]*(i+1)%mod;
}

int C(int n,int m){
	if(m>n) return 0;
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i=2;i<=n;i+=2){
		int tmp = C(i,n-i);
		if(i!=n) tmp = (tmp+C(i-1,n-i-1))%mod;
		tmp = tmp*2%mod;
		tmp = (ll)tmp*fac[i]%mod;
		ans = (ans+tmp)%mod;
	}
	printf("%d\n",ans);
}