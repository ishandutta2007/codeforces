#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int main() {
	int n;
	assert(scanf("%d", &n)==1);
	if(n%2==0) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1, cur=1, step=3; i<=n; ++i, cur+=step, step^=2) printf("%d ", cur);
	for(int i=1, cur=2, step=1; i<=n; ++i, cur+=step, step^=2) printf("%d ", cur);
	puts("");
	return 0;
}