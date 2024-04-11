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
	int num_cases;
	cin >> num_cases;
	while (num_cases--) {
		long long a, b, n;
		cin >> a >> b >> n;
		int ret = 0;
		while (a <= n && b <= n) {
			if (a < b) {
				swap(a, b);
			}
			b += a;
			++ret;
		}
		cout << ret << endl;
	}
	return 0;
}