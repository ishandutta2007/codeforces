#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 400000;
Long a[maxN + 10], k, p, t[maxN + 10];
int n, len, id, ans, ed;
bool fd;

bool Work() {
	Long p = 0;
	for (int i = 0; i <= n; ++i) {
		p += t[i];
		t[i] = abs(p % 2);
		p = (p - t[i]) / 2;
	}
	if (p < 0) return 0;
	len = n;
	while (p) {
		t[++len] = p % 2;
		p /= 2;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i) {
		scanf("%lld", &a[i]);
		t[i] = a[i];
	}
	if (!Work()) {
		for (int i = 0; i <= n; ++i) t[i] = a[i] = -a[i];
		Work();
	}
	for (int i = 0; i <= len; ++i)
		if (t[i]) {
			id = i; break;
		}
	for (int i = len; i >= 0; --i)
		if (t[i]) {
			ed = i; break;
		}
	Long now = 1, val = 0;
	for (int i = id; i <= ed; ++i) {
		val += now * t[i];
		if (now > k * 2 || val > k * 2) {
			printf("0"); return 0;
		}
		now *= 2;
	}
	for (int i = id; i >= 0; --i) {
		if (i <= n && (i != n || a[i] - val)&& a[i] - val >= -k) ++ans;
		val *= 2;
		if (val > k * 2) break;
	}
	printf("%d", ans);
}