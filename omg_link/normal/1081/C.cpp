#include <stdio.h>
#define MN 2000
typedef long long LL;
const int mod=998244353;
int n,m,k,f[MN+5][MN+5];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	f[1][0]=m;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=f[i-1][j];
			if(j!=0) f[i][j]=(f[i][j]+(LL)f[i-1][j-1]*(m-1))%mod;
		}
	}
	printf("%d\n",f[n][k]);
}