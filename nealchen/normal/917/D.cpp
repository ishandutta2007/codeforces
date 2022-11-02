#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>
#include <numeric>
const int N=105, P=1e9+7;
int n, head[N], next[N<<1], to[N<<1], size[N], f[N][N], g[N][N], ff[N], gg[N], s[N], t[N], c[N][N];
long long power(long long x, int y) {
	long long ans=1;
	for(; y; x=x*x%P, y>>=1) if(y&1) ans=ans*x%P;
	return ans;
}
void dfs(int x, int fa) {
	size[x]=1;
	f[x][0]=g[x][0]=1;
	for(int i=head[x]; i; i=next[i])
		if(to[i]!=fa) {
			dfs(to[i], x);
			for(int j=0; j<size[x]; ++j)
				for(int k=0; k<size[to[i]]; ++k) {
					gg[j+k]=(gg[j+k]+(long long)g[x][j]*g[to[i]][k])%P;
					ff[j+k]=(ff[j+k]+(long long)f[x][j]*g[to[i]][k]+(long long)g[x][j]*f[to[i]][k])%P;
					gg[j+k+1]=(gg[j+k+1]+(long long)g[x][j]*f[to[i]][k])%P;
					ff[j+k+1]=(ff[j+k+1]+(long long)f[x][j]*f[to[i]][k])%P;
				}
			size[x]+=size[to[i]];
			memcpy(f[x], ff, size[x]*sizeof(int));
			memcpy(g[x], gg, size[x]*sizeof(int));
			memset(ff, 0, size[x]*sizeof(int));
			memset(gg, 0, size[x]*sizeof(int));
		}
}
int main() {
	assert(scanf("%d", &n)==1);
	for(int i=1, j=2; i<n; ++i) {
		assert(scanf("%d%d", &to[j], &to[j^1])==2);
		next[j]=head[to[j^1]], head[to[j^1]]=j, ++j;
		next[j]=head[to[j^1]], head[to[j^1]]=j, ++j;
	}
	dfs(1, 0);
	for(int i=0; i<n; ++i) s[i]=f[1][n-i-1]*power(n, i==n-1?P-2:n-i-2)%P;
	for(int i=0; i<n; ++i) {
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; ++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	}
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j) {
			int term=(long long)c[j][i]*s[j]%P;
			if(i-j&1) t[i]=(t[i]-term+P)%P; else t[i]=(t[i]+term)%P;
		}
	for(int i=0; i<n; ++i) printf("%d ", t[i]);
	puts("");
	return 0;
}