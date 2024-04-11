#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SGN(x) ((x) < 0 ? -1 : 1)
long long a[200000];
int n, k, x, b[200000];
bool comp(int x, int y) {return ABS(a[x]) > ABS(a[y]);}
int main() {
	int i, j, sgn = 1;
	scanf("%d%d%d", &n, &k, &x);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		sgn *= SGN(j);
		a[i] = j;
		b[i] = i;
	}
	std::make_heap(b, b + n, comp);
	while(k--) {
		j = sgn * SGN(a[b[0]]);
		a[b[0]] -= j * x;
		sgn = j * SGN(a[b[0]]);
		std::pop_heap(b, b + n, comp);
		std::push_heap(b, b + n, comp);
	}
	for(i = 0; i < n; ++i) printf("%I64d ", a[i]);
	return 0;
}