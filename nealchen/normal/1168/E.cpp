#include <cstdio>
#include <cassert>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1<<12;
int k, n, a[N], p[N], q[N], r[N];
void do_xor(int x, int y, int z) {
	int t=r[p[x]^z];
	if(t==x) return;
	if(t==y) {
		std::swap(p[x], p[y]);
		r[p[x]]=x, r[p[y]]=y;
		return;
	}
	std::swap(p[x], p[t]);
	r[p[x]]=x, r[p[t]]=t;
	std::swap(q[y], q[t]);
	do_xor(t, y, z^q[y]^q[t]);
}
int main() {
	assert(scanf("%d", &k)==1);
	n=1<<k;
	for(int i=0; i<n; ++i) assert(scanf("%d", &a[i])==1);
	for(int i=0; i<n; ++i) p[i]=q[i]=r[i]=i;
	for(int i=n; i--; ) {
		do_xor(i-1, i, a[i]);
		a[i-1]^=a[i];
	}
	if(a[0]==0) {
		puts("Shi");
		//puts("1");
		for(int i=0; i<n; ++i) printf("%d%c", p[i], i+1==n?'\n':' ');
		for(int i=0; i<n; ++i) printf("%d%c", q[i], i+1==n?'\n':' ');
	} else {
		puts("Fou");
		//puts("0");
	}
	return 0;
}