#include <stdio.h>
#define MN 200000
typedef long long ll;
const int mod = 1000000007;

int pw[MN+5],fac[MN+5],inv[MN+5];

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
	pw[0] = 1;
	for(int i=1;i<=MN;i++)
		pw[i] = pw[i-1]*2%mod;
}

int C(int n,int m){
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	int bsc = 0;
	for(int i=0;i<n;i+=2)
		bsc = (bsc+C(n,i))%mod;
	int ans;
	if((n&1)==0){
		ans = qpow(bsc,k);
		for(int i=k,pre=1;i>=1;i--,pre=(ll)pre*bsc%mod)
			ans = (ans+(ll)pre*qpow(pw[i-1],n))%mod;
	}else{
		bsc++;
		ans = qpow(bsc,k);
	}
	printf("%d\n",ans);
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--) solve();
}