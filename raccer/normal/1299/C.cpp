#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;

long long a[1000010];
pii st[1000010];

bool check(pii a, pii b, pii c) {
	double k1 = 1.0 * (b.se - a.se) / (b.fi - a.fi);
	double k2 = 1.0 * (c.se - b.se) / (c.fi - b.fi);
	if (k1 > k2) return 1;
	return 0;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	int top = 0;
	st[top++] = mp(0, 0);
	for (int i = 1; i <= n; i++) {
		pii tmp = mp(i, a[i]);
		while (top > 1 && check(st[top - 2], st[top - 1], tmp)) top--;
		st[top++] = tmp;
	}
	for (int i = 0; i < top - 1; i++) {
		long long l = st[i].fi, r = st[i + 1].fi, tot = st[i + 1].se - st[i].se;
		for (int j = l + 1; j <= r; j++) {
			printf("%.9f\n", 1.0 * tot / (r - l));
		}
	}
	return 0;
}