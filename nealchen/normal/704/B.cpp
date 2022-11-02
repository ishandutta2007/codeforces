#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
const int N=5000;
int x[N], a[N], b[N], c[N], d[N];
long long f[2][10010];
int main() {
	int n=rd(), s=rd()-1, e=rd()-1;
	long long *F=f[0], *G=f[1];
	std::generate(x, x+n, rd);
	std::generate(a, a+n, rd);
	std::generate(b, b+n, rd);
	std::generate(c, c+n, rd);
	std::generate(d, d+n, rd);
	memset(F, 63, sizeof(f[0]));
	F[0]=0;
	for(int i=0; i<n; ++i) {
		std::swap(F, G);
		memset(F, 63, sizeof(f[0]));
		for(int j=(i!=0); j<=2*n; ++j) {
			if(G[j]>1e18) continue;
			if(i==s) {
				if(j) cmin(F[j-1], G[j]+c[i]+x[i]);
				cmin(F[j+1], G[j]+d[i]-x[i]);
			} else if(i==e) {
				if(j) cmin(F[j-1], G[j]+a[i]+x[i]);
				cmin(F[j+1], G[j]+b[i]-x[i]);
			} else {
				if(s<e||j>=2) cmin(F[j], G[j]+a[i]+d[i]);
				if(s>e||j>=2) cmin(F[j], G[j]+b[i]+c[i]);
				if(j>=2) cmin(F[j-2], G[j]+a[i]+c[i]+2*x[i]);
				cmin(F[j+2], G[j]+b[i]+d[i]-2*x[i]);
			}
		}
	}
	printf("%lld\n", F[0]);
	return 0;
}