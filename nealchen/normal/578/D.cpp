#include <stdio.h>
const int N=1e5+5;
char s[N];
long long f[N][8];
int main() {
	int n, m;
	register int i, j, k;
	scanf("%d%d%s", &n, &m, s);
	for(i=0; i<n; ++i) s[i]-='a';
	for(i=0; i<m; ++i) ++f[1][(s[0]!=i&s[1]!=i)<<2 | (s[0]!=i)<<1];
	for(i=1; i<n; ++i) {
		for(j=0; j<8; ++j) {
			register int dp=i-(j>>2&1), dz=i-(j>>1&1), dn=i-1-(j&1), pp, zz, nn;
			for(k=0; k<m; ++k) {
				nn = s[i-1]==k ? dn+1 : dz;
				zz = s[i]==k ? dz+1 : nn>dp?nn:dp;
				pp = s[i+1]==k ? dp+1 : zz;
				nn = i-nn, zz=i+1-zz, pp=i+1-pp;
				if(nn<2 && zz<2 && pp<2) f[i+1][pp<<2 | zz<<1 | nn]+=f[i][j];
			}
		}
	}
	printf("%I64d\n", f[n][2]+f[n][3]+f[n][6]+f[n][7]);
	return 0;
}