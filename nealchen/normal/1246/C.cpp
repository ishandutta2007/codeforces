#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;

const int N=2002, P=1e9+7;
int rn[N][N], dn[N][N], f[N][N], g[N][N], sf[N][N], sg[N][N];
char s[N][N];
int main() {
	int n, m;
	assert(scanf("%d%d", &n, &m)==2);
	for(int i=1; i<=n; ++i) assert(scanf("%s", s[i]+1)==1);
	if(n==1&&m==1) {
		puts("1");
		return 0;
	}
	for(int i=n; i>=1; --i)
		for(int j=m; j>=1; --j) {
			rn[i][j]=rn[i][j+1]+(s[i][j]=='R');
			dn[j][i]=dn[j][i+1]+(s[i][j]=='R');
		}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) {
			if(i==1&&j==1) {
				f[i][j]=g[i][j]=1;
			} else {
				/*transform g(i, k) to f(i, j)*/
				/*req: rn[k+1]<=n-j*/
				/*the first <=*/
				int k=std::lower_bound(rn[i]+1, rn[i]+m+1, m-j, std::greater<int>())-rn[i]-1;
				f[i][j]=sg[i][j-1];
				if(k) f[i][j]=(f[i][j]-sg[i][k-1]+P)%P;
				k=std::lower_bound(dn[j]+1, dn[j]+n+1, n-i, std::greater<int>())-dn[j]-1;
				g[i][j]=sf[i-1][j];
				if(k) g[i][j]=(g[i][j]-sf[k-1][j]+P)%P;
			}
			sf[i][j]=(sf[i-1][j]+f[i][j])%P;
			sg[i][j]=(sg[i][j-1]+g[i][j])%P;
		}
	printf("%d\n", (f[n][m]+g[n][m])%P);
	return 0;
}