#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	for (int case_id = 0; case_id < num_cases; ++case_id) {
		int n;
		cin >> n;
		ll s = 0;
		ll x = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			s += a;
			x ^= a;
		}
		cout << 2 << endl;
		cout << x << " " << s + x << endl;
	}
	return 0;
}