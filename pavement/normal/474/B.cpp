#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, s = 0, tmp;
	scanf("%d", &n);
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		s += tmp;
		a[i] = make_pair(s, i + 1);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &tmp);
		int lo = 0, hi = n - 1, ans;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid].first >= tmp) {
				ans = a[mid].second;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
}