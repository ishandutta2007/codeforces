#include <stdio.h>
#include <algorithm>
const int N = 6e5;
int n, k, c[N], a[N], heap[N], top = 0;
bool cmp(register int x, register int y) {return c[x] < c[y];}
int main() {
	register int i;
	long long cost = 0, ans = 0;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; ++i) scanf("%d", &c[i]);
	for(i = 0; i < n + k; ++i) {
		if(i < n) heap[top++] = i, std::push_heap(heap, heap + top, cmp), cost += c[i];
		if(i >= k) cost -= c[heap[0]], a[heap[0]] = i + 1, std::pop_heap(heap, heap + top--, cmp);
		ans += cost;
	}
	printf("%lld\n", ans);
	for(i = 0; i < n; ++i) printf("%d ", a[i]);
	return 0;
}