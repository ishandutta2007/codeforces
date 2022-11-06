#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int a[n], c[n + 1] = {}, l = 0, ans = 1e9;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		multiset<int> s;
		for (int i = 0; i < n; i++) s.insert(0);
		for (int i = 0; i < n; i++) {
			s.erase(s.find(c[a[i]]));
			s.insert(++c[a[i]]);
			if (i - l + 1 >= 2 && *s.rbegin() > *(++s.rbegin())) ans = min(ans, i - l + 1);
			while (i - l + 1 > 2 && *s.rbegin() > *(++s.rbegin())) {
				s.erase(s.find(c[a[l]]));
				s.insert(--c[a[l++]]);
				if (i - l + 1 >= 2 && *s.rbegin() > *(++s.rbegin())) ans = min(ans, i - l + 1);
			}
			if (i - l + 1 >= 2 && *s.rbegin() > *(++s.rbegin())) ans = min(ans, i - l + 1);
		}
		printf("%d\n", ans == 1e9 ? -1 : ans);
	}
}