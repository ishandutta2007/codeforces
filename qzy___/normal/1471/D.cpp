#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

int T, n, a[N], q, f[1000010];

int main() {
	for (int i = 1; i <= 1000000; i++) f[i] = -1;
	for (int i = 1000; i >= 2; i--)
		for (int j = 1; j * i * i <= 1000000; j++)
			if (f[j * i * i] == -1) f[j * i * i] = j;
	for (scanf("%d", &T); T; T--) {
		map <int,int> m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			while (f[a[i]] != -1) a[i] = f[a[i]];
			m[a[i]]++;
		}
		int ans1 = 0, ans2 = 0;
		for (auto i : m) {
			ans1 = max(ans1, i.second);
			if (i.second % 2 == 0 || i.first == 1)
				ans2 += i.second;
		}
		ans2 = max(ans1, ans2);
		scanf("%d", &q);
		while (q--) {
			long long w; scanf("%lld", &w);
			if (w != 0) printf("%d\n", ans2);
			else printf("%d\n", ans1);
		}
	}
	return 0;
}