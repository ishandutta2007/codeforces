#include <stdio.h>

#define N 100010
#define LL long long

LL tree[N];
LL arr[N];
int n, m;

LL max(LL a, LL b) {
	return a > b ? a : b;
}
void update(int idx, LL val) {
	while(idx <= n) {
		tree[idx] = max(tree[idx], val);
		idx += idx & (-idx);
	}
}
LL query(int idx) {
	LL ans = 0;
	while(idx > 0) {
		ans = max(ans, tree[idx]);
		idx -= idx & (-idx);
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}
	scanf("%d", &m);
	for(int i = 0;i < m;i++) {
		int x, h;
		scanf("%d%d", &x, &h);
		LL k = query(x);
		update(1, (LL) k + h);
		printf("%I64d\n", k);
	}
	return 0;
}