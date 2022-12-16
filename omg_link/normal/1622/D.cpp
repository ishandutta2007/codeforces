#include <stdio.h>
#define MN 5000

const int mod = 998244353;

int n,m,k,f[MN+5],p[MN+5],C[MN+5][MN+5];

void init(int n){
	for(int i=0;i<=n;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
	}
}

int calc1(int k){
	int ans = 0;
	for(int i=k;i<=m;i++){
		int len = p[i+1]-p[i-k]-1;
		ans = (ans+C[len][k]-1)%mod;
	}
	return ans;
}

int calc2(int k){
	if(k==0) return 0;
	int ans = 0;
	for(int i=k+1;i<=m-1;i++){
		int len = p[i+1]-p[i-k]-1;
		ans = (ans+C[len][k]-1)%mod;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%1d",&a);
		if(a==1) p[++m] = i;
	}
	if(k==0||k>m){
		puts("1");
		return 0;
	}
	init(n);
	p[m+1] = n+1;
	int ans = calc1(k)-calc2(k-1)+1;
	ans = (ans%mod+mod)%mod;
	printf("%d\n",ans);
}