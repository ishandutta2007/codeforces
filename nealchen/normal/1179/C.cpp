#include <cstdio>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=3e5;
int a[N], b[N], max[1<<21], tag[1<<21];
void prefix_add(int x, int v) {
	for(x=x+1|1<<20; x!=1; x>>=1, max[x]+=tag[x]) {
		if(x&1) tag[x^1]+=v, max[x^1]+=v;
		max[x>>1]=std::max(max[x], max[x^1]);
	}
}
int last_positive() {
	int i, lim=0;
	for(i=1; i<1<<20; i|=max[i+1]>lim) lim-=tag[i], i<<=1;
	i^=1<<20;
	return i?i:-1;
}
int main() {
	int n, m, q;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
		prefix_add(a[i], 1);
	}
	for(int i=0; i<m; ++i) {
		scanf("%d", &b[i]);
		prefix_add(b[i], -1);
	}
	scanf("%d", &q);
	while(q--) {
		int op, i, x;
		scanf("%d%d%d", &op, &i, &x);
		--i;
		if(op==1) {
			prefix_add(a[i], -1);
			prefix_add(a[i]=x, 1);
		} else {
			prefix_add(b[i], 1);
			prefix_add(b[i]=x, -1);
		}
		printf("%d\n", last_positive());
	}
	return 0;
}