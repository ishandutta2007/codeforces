#include <stdio.h>
#include <assert.h>
#include <string.h>
#define N 200000
const unsigned P=998244353;
unsigned long long power(unsigned long long a, int b) {
	unsigned long long ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}
int a[N];
unsigned w[N], f[2][3001][3001], inv[6001];
int main() {
	int n, m, sum[2]={};
	assert(scanf("%d%d", &n, &m)==2);
	for(int i=0; i<n; ++i) assert(scanf("%d", &a[i])==1);
	for(int i=0; i<n; ++i) {
		assert(scanf("%d", &w[i])==1);
		(sum[a[i]]+=w[i])>=P?(sum[a[i]]-=P):0;
	}
	for(int i=0; i<=2*m; ++i) inv[i]=power(sum[0]+sum[1]+i-m, P-2)%P;
	for(int k=0; k<2; ++k)
		for(int i=m; i>=0; --i) {
			f[k][i][m-i]=1;
			for(int j=m-i-1; j>=0; --j)
				f[k][i][j]=((unsigned long long)f[k][i][j+1]*(sum[0]-j-!k)+(unsigned long long)f[k][i+1][j]*(sum[1]+i+k))%P*inv[m+i-j]%P;
		}
	for(int i=0; i<n; ++i) printf("%u\n", (unsigned)((unsigned long long)f[a[i]][0][0]*w[i]%P));
	return 0;
}