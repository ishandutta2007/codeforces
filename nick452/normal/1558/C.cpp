#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

vector<int> solve(const vector<int>& a) {
	int n = a.size();
	while (n > 1 && a[n - 1] == n - 1 && a[n - 2] == n - 2) {
		n -= 2;
	}
	if (n <= 1) {
		return {};
	}
	int p = find(a.begin(), a.end(), n - 1) - a.begin();
	int q = find(a.begin(), a.end(), n - 2) - a.begin();
	if (p == 0 && q == 1) {
		return { n };
	}
	if (p + 1 == q) {
		return { q + 2 };
	}
	if (p != 0) {
		return {p + 1};
	}
	if (q + 1 == p) {
		return { p + 1 };
	}
	return {q};
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
		}
		int ok = 1;
		for (int i = 0; i < n; ++i) {
			if ((a[i] + i) % 2) {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			printf("-1\n");
			continue;
		}
		vector<int> r;
		while (1) {
			vector<int> t = solve(a);
			if (t.empty()) {
				break;
			}
			for (int x : t) {
				assert(x % 2 == 1);
				if (x > 1) {
					r.push_back(x);
					reverse(a.begin(), a.begin() + x);
				}
			}
		}
		printf("%d\n", r.size());
		for (int t : r) {
			printf("%d ", t);
		}
		printf("\n");
	}
	return 0;
}