#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=1000;
int n, a[N][N];
int main() {
	int i, j, k=0, x, y, m;
	assert(scanf("%d", &n)==1);
	m=n/4;
	for(i=0; i<4; ++i) for(j=0; j<4; ++j) {
		k=i*4+j;
		for(x=0; x<m; ++x) for(y=0; y<m; ++y) {
			a[i*m+x][j*m+y]=k;
			k+=16;
		}
	}
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}