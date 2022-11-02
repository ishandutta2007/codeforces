#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int main() {
	int n, m, x, y, l=0, r=2e9;
	assert(scanf("%d%d%d%d", &n, &m, &x, &y)==4);
	while(l<r) {
		int v=(r-l)/2+l, both=v/x/y, xonly=v/x-both, yonly=v/y-both, neither=v-xonly-yonly-both;
		if(std::max(0, m-xonly)+std::max(0, n-yonly)<=neither) r=v; else l=v+1;
	}
	printf("%d\n", l);
	return 0;
}