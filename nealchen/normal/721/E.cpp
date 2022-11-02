#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+1;
int n, p, t, l[N], r[N], f[N], g[N];
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
void update(int i, int v, int l, int r) {
	int ff=v+(r-l)/p, gg=r-(r-l)%p+t;
	if(cmax(f[i], ff)) g[i]=gg; else if(f[i]==ff) cmin(g[i], gg);
}
int main() {
	int (*rd)()=read<int>, ans=0;
	rd(), n=rd(), p=rd(), t=rd();
	for(int i=1, j=0; i<=n; ++i) {
		int l=rd(), r=rd();
		if(j) --j;
		for(; j<i&&g[j]<=r; ++j) update(i, f[j], std::max(g[j], l), r);
		cmax(ans, f[i]);
		if(cmax(f[i], f[i-1])) g[i]=g[i-1]; else if(f[i-1]==f[i]) cmin(g[i], g[i-1]);
	}
	printf("%d\n", ans);
	return 0;
}