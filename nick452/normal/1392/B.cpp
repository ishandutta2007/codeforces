#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	while (num_cases--) {
		int n;
		long long k;
		cin >> n >> k;
		if (k >= 5) {
			k -= (k - 5) / 2 * 2;
		}
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		while (k--) {
			int d = *max_element(a.begin(), a.end());
			for (int i = 0; i < n; i++) {
				a[i] = d - a[i];
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}