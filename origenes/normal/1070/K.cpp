#include <bits/stdc++.h>

using namespace std;

const int maxn = 123456;

int k, n, a[maxn];

int main() {
	scanf("%d%d", &n, &k);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		s += a[i];
	}
	if (s % k) {
		puts("No");
		return 0;
	}
	int bd = s / k;
	int now = 0, p = 0, pv = 0;
	vector<int> ans;
	while (now <= bd && p <= n) {
		if (now == bd) {
			now = 0;
			ans.push_back(p - pv);
			pv = p;
		}
		p++;
		now = now + a[p];
	}
	if (p == n + 1) {
		puts("Yes");
		for (int it : ans) printf("%d ", it);
	} else {
		puts("No");
	}
	return 0;
}