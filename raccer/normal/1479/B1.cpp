#include <bits/stdc++.h>
using namespace std;

int a[100010];
vector <int> all;

int main () {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (!all.size() || abs(all.back()) != a[i]) all.push_back(a[i]);
		else all.back() = -a[i];
	}
	int ans = 0;
	for (int i = 0; i < all.size(); i++) {
		if (all[i] < 0) ans += 2;
		else ans += 1;
	}
	for (int i = 0; i < all.size(); i++) {
		if (all[i] < 0) continue;
		int j = i;
		while (j < all.size() && all[j] > 0) j++;
		int x = i ? all[i - 1] : 0x3f3f3f3f, y = j == all.size() ? -0x3f3f3f3f - 1 : all[j];
		if (x == y) {
			int pd = 1;
			for (int k = i; k < j; k++) {
				if (abs((k == i ? x : all[k - 1])) != abs((k + 1 == j ? y : all[k + 1])) && all[k] != -x) {
					pd = 0;
					break;
				}
			}
			ans -= pd;
		}
		i = j - 1;
	}
	printf("%d\n", ans);
	return 0;
}