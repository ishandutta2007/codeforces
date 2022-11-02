#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define meow(args...) fprintf(stderr, args)
const int P=998244353;
int n, c, a[3000], f[3001], ff[3001][1<<12], cnt[3000], key[3001], ikey[3001];
int F()
{
	int a=0;
	unsigned char c;
	while((c=getchar()-48)>9);
	while(a=a*10+c, (c=getchar()-48)<=9);
	return a;
}
long long power(long long a, int b)
{
	long long ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}
int main()
{
	n=F(), c=F();
	for(int i=0; i<n; ++i) a[i]=F()-1;
	if(c<=log2(n)) {
		int fs=(1<<c)-1, ans=-1;
		ff[0][0]=1;
		for(int i=n; i--; ) {
			for(int j=n/c; j>=0; --j) {
				for(int k=0; (k|=1<<a[i])<fs; ++k) ff[j][k]=(ff[j][k]*2ll+ff[j][k^1<<a[i]])%P;
				if(j) ff[j][0]=(ff[j][0]+ff[j-1][fs^1<<a[i]])%P;
			}
		}
		for(int j=0; j<fs; ++j) ans=(ans+ff[0][j])%P;
		printf("%d", ans);
		for(int i=1; i<=n/c; ++i) {
			ans=0;
			for(int j=0; j<fs; ++j) ans=(ans+ff[i][j])%P;
			printf(" %d", ans);
		}
		for(int i=n/c+1; i<=n; ++i) printf(" 0");
		printf("\n");
	} else {
		for(int i=1; i<=n; ++i) {
			key[i]=(key[i-1]*2+1)%P;
			ikey[i]=power(key[i], P-2)%P;
		}
		ff[n][0]=1;
		for(int i=n; i--; ) {
			int nzero=c-1;
			long long g=1;
			memset(cnt, 0, c*sizeof(int));
			for(int j=i; j<n; ++j) {
				if(a[j]!=a[i]) {
					if(cnt[a[j]]) g=g*ikey[cnt[a[j]]]%P; else --nzero;
					g=g*key[++cnt[a[j]]]%P;
				}
				if(nzero==0&&g) for(int k=0; k<=(n-j)/c; ++k) if(ff[j+1][k]) ff[i][k+1]=(ff[i][k+1]+ff[j+1][k]*g)%P;
			}
		}
		for(int i=0; i<=n; ++i) for(int j=0; j<=n/c; ++j) f[j]=(f[j]+ff[i][j]*(key[i]+1ll))%P;
		--f[0];
		for(int i=0; i<n; ++i) if((f[i]-=f[i+1])<0) f[i]+=P;
		for(int i=0; i<n; ++i) printf("%d ", f[i]);
		printf("%d\n", f[n]);
	}
	return 0;
}