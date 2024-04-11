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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> s(n + 1);
	for (int i = 0; i < n; ++i) {
		s[i + 1] = (s[i] ^ a[i]);
	}
	for (int result = 1; result <= n; ++result)
	{
		for (int i = 0; i <= n; ++i) {
			int k = i + result + 2;
			if (k > n) {
				break;
			}
			for (int j = i + 1; j <= n && j - i <= result + 1; ++j) {
				if ((s[i] ^ s[j]) > (s[j] ^ s[k])) {
					printf("%d\n", result);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}