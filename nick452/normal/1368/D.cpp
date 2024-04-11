#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	vector<int> c(20);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < 20; j++) {
			if (a & (1 << j)) {
				++c[j];
			}
		}
	}
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		long long a = 0;
		for (int j = 0; j < 20; j++) {
			if (c[j] > i) {
				a |= (1 << j);
			}
		}
		ret += a * a;
	}
	cout << ret << endl;
	return 0;
}