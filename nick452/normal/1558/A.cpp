#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, vector<int>& r) {
	int n = a + b;
	int c2 = n / 2;
	int c1 = n  - c2;
	for (int x1 = 0; x1 <= c1; ++x1) {
		int y1 = c1 - x1;
		int x2 = b - y1;
		int y2 = c2 - x2;
		if (y1 >= 0 && x2 >= 0 && y2 >= 0) {
			r[y1 + y2] = 1;
		}
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		int a, b;
		cin >> a >> b;
		vector<int> r(a + b + 1);
		solve(a, b, r);
		solve(b, a, r);
		printf("%d\n", accumulate(r.begin(), r.end(), 0));
		for (int i = 0; i < r.size(); ++i) {
			if (r[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}