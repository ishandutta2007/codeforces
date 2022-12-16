#include <stdio.h>
#define MN 1000000

using ll = long long;

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

void init(int n){
	fac[0] = 1;
	for(int i=1;i<=n;i++){
		fac[i] = (ll)fac[i-1]*i%mod;
	}
	inv[n] = qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i] = (ll)inv[i+1]*(i+1)%mod;
	}
}

int C(int n,int m){
	if(m==0) return 1;
	if(n-m<0||n<0||m<0) return 0;
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ans = 0;
	for(int i=0;i<=m;i++){
		ans = (ans+(ll)i*C(n-i-1,m-i)%mod*qpow(500000004,n-i))%mod;
	}
	ans = (ll)ans*k%mod;
	printf("%d\n",ans);
}

int main(){
	init(MN);
	int T;
	scanf("%d",&T);
	while(T--) solve();
}