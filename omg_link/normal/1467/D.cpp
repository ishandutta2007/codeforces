#include <stdio.h>
#define MN 5000
#define MK 5000
const int mod=1000000007;

int n,k,q,a[MN+5],c[MK+5][MN+5],cc[MN+5];

int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++){
		c[0][i] = 1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			c[i][j] = (c[i-1][j-1]+c[i-1][j+1])%mod;
		}
	}
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n;j++){
			cc[j] = (cc[j]+1ll*c[i][j]*c[k-i][j])%mod;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans = (ans+1ll*a[i]*cc[i])%mod;
	}
	for(int i,x;q--;){
		scanf("%d%d",&i,&x);
		ans = ((ans-1ll*a[i]*cc[i])%mod+mod)%mod;
		a[i] = x;
		ans = (ans+1ll*a[i]*cc[i])%mod;
		printf("%d\n",ans);
	}
}