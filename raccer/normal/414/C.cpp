#include <bits/stdc++.h>
using namespace std;

int N;
long long f[30], g[30];
int a[1 << 20];
int tmp[1 << 20];

void Build(int l, int r, int dep = 0) {
	if (l == r) return ;
	int mid = l + r >> 1;
	Build(l, mid, dep + 1), Build(mid + 1, r, dep + 1);
	int p1 = l, p2 = mid + 1, cur = l;
	long long sum = 0, sss = 0;
	while (p1 <= mid || p2 <= r) {
		if (p2 == r + 1 || (p1 <= mid && a[p1] <= a[p2])) tmp[cur++] = a[p1++], sum += p2 - mid - 1;
		else tmp[cur++] = a[p2++];
	}
	int pos = mid + 1;
	for (int i = l; i <= mid; i++) {
		while (pos <= r && a[pos] <= a[i]) pos++;
		sss += r - pos + 1;
	}
	f[dep] += sum;
	g[dep] += sss;
	for (int i = l; i <= r; i++) {
		a[i] = tmp[i];
	}
}

int main () {
	int n; scanf("%d", &n);
	N = 1 << n;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	Build(0, N - 1, 0);
	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x), x = n - x;
		for (int i = x; i < n; i++) {
			swap(f[i], g[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += f[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}