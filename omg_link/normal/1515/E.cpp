#include <stdio.h>
#include <string.h>
#define MN 400
typedef long long LL;

int n,mod,f[2][MN+5][MN+5],g[MN+5];
int fac[MN+5],inv[MN+5];

LL qpow(LL bsc,int y){
	LL ret = 1;
	while(y){
		if(y&1) ret = ret*bsc%mod;
		bsc = bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&mod);
	fac[0] = 1;
	for(int i=1;i<=n;i++){
		fac[i] = (LL)fac[i-1]*i%mod;
	}
	inv[n] = qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i] = (LL)inv[i+1]*(i+1)%mod;
	}
	g[1] = 1;
	for(int i=2;i<=n;i++)
		g[i] = g[i-1]*2ll%mod;
	f[0][0][0] = 1;
	for(int i=1;i<=n+1;i++){
		int S = i&1;
		int T = S^1;
		memset(f[S],0,sizeof(f[S]));
		for(int tot=0;tot<=i-1;tot++){
			for(int lst=0;lst<=tot;lst++){
				f[S][tot+1][lst+1] = (f[S][tot+1][lst+1]+f[T][tot][lst])%mod;
				if(lst!=0){
					f[S][tot][0] = (f[S][tot][0]+(LL)f[T][tot][lst]*inv[lst]%mod*g[lst]%mod)%mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = (ans+(LL)fac[i]*f[(n+1)&1][i][0])%mod;
	}
	printf("%d\n",ans);
}