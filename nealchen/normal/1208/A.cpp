#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int main() {
	int t;
	assert(scanf("%d", &t)==1);
	while(t--) {
		int a, b, n;
		assert(scanf("%d%d%d", &a, &b, &n)==3);
		if(n%3==0) printf("%d\n", a);
		if(n%3==1) printf("%d\n", b);
		if(n%3==2) printf("%d\n", a^b);
	}
	return 0;
}