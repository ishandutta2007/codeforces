#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int a[1000000], fir[1<<21], sec[1<<21];
int main() {
	int n;
	assert(scanf("%d", &n)==1);
	for(int i=0; i<n; ++i) {
		assert(scanf("%d", a+i)==1);
		sec[a[i]]=fir[a[i]];
		fir[a[i]]=i;
	}
	for(int i=1<<21; i--; )
		for(int j=i; j; j&=j-1) {
			int k=i ^ j&-j;
			if(fir[i]>fir[k]) {
				sec[k]=std::max(fir[k], sec[i]);
				fir[k]=fir[i];
			} else if(fir[k]==fir[i]) {
				cmax(sec[k], sec[i]);
			} else {
				cmax(sec[k], fir[i]);
			}
		}
	int ans=0;
	for(int i=n-2; i--; ) {
		int w=0;
		for(int j=21; j--; ) {
			if(a[i]>>j&1) continue;
			if(sec[w|1<<j]>i) w|=1<<j;
		}
		cmax(ans, a[i]+w);
	}
	printf("%d\n", ans);
	return 0;
}