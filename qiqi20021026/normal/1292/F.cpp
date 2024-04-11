#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 62

const LL mod=1000000007;
LL n,m,p,a[N],C[N][N],f[N][1<<18],bit[N],cnt[1<<18],fac[N],vis[N];

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for (LL i=1;i<=n;++i){
		if (!vis[i]){
			bool fl=0;
			vis[i]=m;
			for (LL j=i+1;j<=n;++j)
				if (a[j]%a[i]==0){
					vis[j]=-1;
					bit[j]|=1<<vis[i];
					fl=1;
				}
			if (fl) ++m;
			else{vis[i]=-2; ++p;}
		}
	}
	for (LL i=1;i<=n;++i)
		if (vis[i]==-1) ++cnt[bit[i]];
	for (LL i=(1<<m)-1;~i;--i)
		for (LL j=i;j;j=(j-1)&i) cnt[i]+=cnt[i^j];
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	for (LL i=0;i<=n;++i){
		C[i][0]=1;
		for (LL j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0][0]=1;
	for (LL i=1;i<=n;++i)
		if (vis[i]==-1){
			for (LL j=i-1;~j;--j)
				for (LL k=0;k<1<<m;++k)
					upd(f[j+1][k|bit[i]],f[j][k]);
		}
	for (LL i=0;i<=n-m-p;++i){
		for (LL j=0;j<1<<m;++j)
			if (f[i][j]) f[i][j]=f[i][j]*fac[cnt[j]-i]%mod*C[n-m-p-i][cnt[j]-i];
		for (LL j=0;j<1<<m;++j)
			for (LL k=1;k<=n;++k)
				if (vis[k]==-1&&(bit[k]&j)!=0&&(bit[k]|j)!=j){
					LL jj=j|bit[k];
					upd(f[i][jj],f[i][j]*C[n-m-p-cnt[j]-1][cnt[jj]-cnt[j]-1]%mod*fac[cnt[jj]-cnt[j]-1]);
				}
		if (f[i][(1<<m)-1]){
			printf("%lld\n",f[i][(1<<m)-1]);
			return 0;
		}
	}
	
	return 0;
}