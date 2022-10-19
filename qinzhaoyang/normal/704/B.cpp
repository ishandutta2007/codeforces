#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
typedef long long ll;
inline void ckmin(ll &x, ll y) {x = x < y ? x : y;} 

int n, s, e, a[N], b[N], c[N], d[N], x[N];
ll f[N][N];

int main() {
	scanf("%d%d%d", &n, &s, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += x[i];
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i] -= x[i];
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]), c[i] += x[i];
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]), d[i] -= x[i];
	memset(f, 0x3f, sizeof f), f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == s) {
			for (int j = (i > e); j < i; j++) {
				if (j >= 1) ckmin(f[i][j], f[i - 1][j] + c[i]);
				ckmin(f[i][j + 1], f[i - 1][j] + d[i]);
			}
		}
		else if (i == e) {
			for (int j = (i > s); j < i; j++) {
				if (j >= 1) ckmin(f[i][j], f[i - 1][j] + a[i]);
				ckmin(f[i][j + 1], f[i - 1][j] + b[i]);
			}
		}
		else {
			for (int j = (i > s) + (i > e); j < i; j++) {
				if (j > (i > s)) ckmin(f[i][j], f[i - 1][j] + b[i] + c[i]);
				if (j > (i > e)) ckmin(f[i][j], f[i - 1][j] + a[i] + d[i]); 
				if (j >= 2) ckmin(f[i][j - 1], f[i - 1][j] + a[i] + c[i]);
				ckmin(f[i][j + 1], f[i - 1][j] + b[i] + d[i]);
			}
		}
	}
	printf("%lld", f[n][1]);
	return 0;
}