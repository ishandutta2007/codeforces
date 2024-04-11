#include <cstdio>
#include <cstring>
const int P=10007, N=412;
int siz, ans[N][N], lessans[N][N], trans[N][N], nep[205], eqp[105], mip[105], f[205][205][205];
void mul(register int (*a)[N], register int (*b)[N])
{
	static int ans[N][N];
	for(register int i=0; i<siz; ++i) memset(ans[i], 0, siz*sizeof(int));
	for(register int i=0; i<siz; ++i)
		for(register int j=i; j<siz; ++j)
			if(a[i][j])
				for(register int k=j; k<siz; ++k)
					ans[i][k]=(ans[i][k]+a[i][j]*b[j][k])%P;
	for(register int i=0; i<siz; ++i) memcpy(a[i], ans[i], siz*sizeof(int));
}
int main()
{
	static char s[201];
	int n, m, odd, eq;
	scanf("%s%d", s, &m);
	n=strlen(s);
	odd=(n+m)%2;
	m=(n+m)/2;
	eq=(n+1)/2;
	siz=n+2*eq+1;
	for(int i=1; i<=n; ++i) {
		nep[i]=n-i;
		trans[nep[i]][nep[i]]=24;
	}
	for(int i=1; i<=eq; ++i) {
		mip[i]=n+i-1;
		trans[mip[i]][mip[i]]=25;
	}
	mip[0]=nep[1], nep[0]=mip[1];
	for(int i=0; i<=eq; ++i) {
		eqp[i]=mip[i]+eq+1;
		trans[eqp[i]][eqp[i]]=26;
		trans[mip[i]][eqp[i]]=1;
	}
	for(int i=1; i<=n; ++i) trans[nep[i]][nep[i-1]]=1;
	for(int i=1; i<eq; ++i) trans[mip[i]][mip[i+1]]=1;
	if(odd) {
		for(int i=0; i<siz; ++i) lessans[i][i]=1;
		for(int i=0; i<siz; ++i) memcpy(ans[i], trans[i], siz*sizeof(int));
		for(; m; m>>=1, mul(trans, trans)) if(m&1) mul(lessans, trans);
		mul(ans, lessans);
	} else {
		for(int i=0; i<siz; ++i) ans[i][i]=1;
		for(; m; m>>=1, mul(trans, trans)) if(m&1) mul(ans, trans);
	}
	f[0][n][0]=1;
	for(int i=0; i<=n; ++i)
		for(int j=n; j>i; --j)
			for(int k=0; k<=n+i-j; ++k) if(f[i][j][k])
				if(s[i]==s[j-1])
					f[i+1][j-1][k]=(f[i+1][j-1][k]+f[i][j][k])%P;
				else {
					f[i][j-1][k+1]=(f[i][j-1][k+1]+f[i][j][k])%P;
					f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k])%P;
				}
	int tot=0;
	for(int i=0; i<=n; ++i)
		for(int j=i?i-1:0; j<=i; ++j)
			for(int k=0; k<=n; ++k) if(f[i][j][k]) {
				int tmp=ans[nep[k]][eqp[(n-k+1)/2]];
				if(odd && j==i) tmp=(tmp+P-lessans[nep[k]][mip[(n-k+1)/2]])%P;
				tot=(tot+tmp*f[i][j][k])%P;
			}
	printf("%d\n", tot);
	return 0;
}