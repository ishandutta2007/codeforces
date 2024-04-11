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
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int n, m, a[12][2000], max[2000], hub[2000], f[1<<12], val[1<<12];
void work() {
	int (*rd)()=read<int>;
	n=rd(), m=rd();
	memset(max, 0, m*sizeof(int));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cmax(max[j], a[i][j]=rd());
	for(int i=0; i<m; ++i) hub[i]=i;
	std::sort(hub, hub+m, [](int x, int y) {return max[x]>max[y];});
	cmin(m, n);
	int fs=(1<<n)-1;
	memset(f, 0, sizeof(int)<<n);
	for(int i=0; i<m; ++i) {
		for(int j=0; j<=fs; ++j) {
			val[j]=0;
			for(int b=0; b<n; ++b) if(j>>b&1) val[j]+=a[b][hub[i]];
		}
		for(int k=0; k<n; ++k) for(int j=0; j<=fs; ++j) cmax(val[j>>1|(j&1)<<n-1], val[j]);
		for(int j=fs; j; --j)
			for(int k=j; k; k=k-1&j)
				cmax(f[j], f[j^k]+val[k]);
	}
	printf("%d\n", f[fs]);
}
int main() {
	int t=read<int>();
	while(t--) work();
	return 0;
}