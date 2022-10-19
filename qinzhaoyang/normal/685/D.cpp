#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

struct Op {
	int x, y1, y2, op;
}	o[N << 1];
int cnt = 0;

inline int operator < (Op A, Op B) {
	return A.x < B.x;
}

int n, k, v[N << 1], cur;
int len1, len2, c[N << 1];
ll ans[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		o[++cnt] = (Op){x, y, y + k, 1};
		o[++cnt] = (Op){x + k, y, y + k, -1};
		v[++cur] = y, v[++cur] = y + k;
	}
	sort (o + 1, o + cnt + 1);
	sort (v + 1, v + cur + 1);
	cur = unique(v + 1, v + cur + 1) - v - 1;
	for (int i = 1; i <= cnt; i++) {
		len1 = o[cnt].x - o[i].x;
		int l = lower_bound(v + 1, v + cur + 1, o[i].y1) - v;
		int r = lower_bound(v + 1, v + cur + 1, o[i].y2) - v;
		for (int j = l; j < r; j++) {
			len2 = v[j + 1] - v[j];
			ans[c[j]] -= 1ll * len1 * len2;
			c[j] += o[i].op;
			ans[c[j]] += 1ll * len1 * len2;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]); puts("");
	return 0;
}