#include<bits/stdc++.h>

using namespace std;

#define N 105
#define LL long long

const LL mod=1000000007;
LL n,m,p,ans,c[N][N],f[2][N][N][N];

void upd(LL &x,LL y){x=((x+y)%mod+mod)%mod;}

int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for (LL i=0;i<=n;++i){
		c[i][0]=1;
		for (LL j=1;j<=i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (LL i=1;i<=n;++i) f[1][i][i][1]=1;
	for (LL i=2;i<=m;++i){
		memset(f[i&1],0,sizeof f[0]);
		for (LL j=1;j<=n;++j)
			for (LL k=1;k<=n;++k)
				for (LL l=1;l<=p;++l)
					if (f[(i&1)^1][j][k][l])
						for (LL t=k;t<=n-j;++t)
							if (l*c[t-1][k-1]<=p)
								upd(f[i&1][j+t][t-k][l*c[t-1][k-1]],f[(i&1)^1][j][k][l]);
		for (LL j=1;j<=n;++j)
			for (LL l=1;l<=p;++l)
				upd(ans,f[i&1][j][0][l]*(m-i+1));
	}
	printf("%lld\n",ans);
	
	return 0;
}