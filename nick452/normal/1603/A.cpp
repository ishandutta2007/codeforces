#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (n > 0) {
		int k = n - 1;
		while (k >= 0 && a[k] % (k + 2) == 0) {
			--k;
		}
		if (k < 0) {
			break;
		}
		--n;
		for (; k < n; k++) {
			a[k] = a[k + 1];
		}
	}
	if (n == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (; t > 0; --t) {
		solve();
	}
	return 0;
}