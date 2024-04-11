#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		int s = 0;
		for (int i = 0; i < n; ++i) {
			s += w[i];
		}
		if (s == x) {
			printf("NO\n");
			continue;
		}
		s = 0;
		for (int i = 0; i < n; ++i) {
			s += w[i];
			if (s == x) {
				s -= w[i];
				swap(w[i], w[i + 1]);
				--i;
			}
		}
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ", w[i]);
		}
		printf("\n");
	}
	return 0;
}