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
int n, m, a[4][100], max[100], hub[100], off[100], ans;
void search(int x) {
	if(x==0) {
		off[0]=0;
		search(1);
	} else if(x<n&&x<m) {
		int &i=off[x];
		for(i=0; i<n; ++i) search(x+1);
	} else {
		int cur=0;
		for(int i=0; i<n; ++i) {
			int rmax=0;
			for(int j=0; j<x; ++j) cmax(rmax, a[(i+off[j])%n][hub[j]]);
			cur+=rmax;
		}
		cmax(ans, cur);
	}
}
void work() {
	int (*rd)()=read<int>;
	n=rd(), m=rd();
	memset(max, 0, m*sizeof(int));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cmax(max[j], a[i][j]=rd());
	for(int i=0; i<m; ++i) hub[i]=i;
	std::sort(hub, hub+m, [](int x, int y) {return max[x]>max[y];});
	ans=0;
	search(0);
	printf("%d\n", ans);
}
int main() {
	int t=read<int>();
	while(t--) work();
	return 0;
}