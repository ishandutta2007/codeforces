#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
int x[N], y[N];
int b[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		a[l]++;
		a[r + 1]--;
	}
	for (int i = 1; i <= m; i++) {
		a[i] += a[i - 1];
	}
	n = m;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int pos = upper_bound(b + 1, b + mx + 1, a[i]) - b;
		b[pos] = a[i];
		mx = max(mx, pos);
		x[i] = pos;
	}
	memset(b, 0, sizeof b);
	mx = 0;
	for (int i = n; i; i--) {
		int pos = upper_bound(b + 1, b + mx + 1, a[i]) - b;
		b[pos] = a[i];
		mx = max(mx, pos);
		y[i] = pos;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, x[i] + y[i] - 1);
	}
	cout << res << endl;
	return 0;
}