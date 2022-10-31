#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(string s0, string s1) {
	int n = s0.size();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] |= (1 << (s0[i] - '0'));
		a[i] |= (1 << (s1[i] - '0'));
	}
	vector<int> prev(4, -1);
	vector<int> c{-1, 1, 0, 2};
	vector<int> f(n + 1);
	for (int i = 0; i < n; ++i) {
		prev[a[i]] = i;
		for (int k = 1; k <= 3; ++k) {
			if (prev[k] >= 0) {
				int val = 0;
				for (int j = 1; j <= 3; ++j) {
					if (prev[j] >= prev[k]) {
						val |= j;
					}
				}
				f[i + 1] = max(f[i + 1], f[prev[k]] + c[val]);
			}
		}
	}
	return f[n];
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
		string s0, s1;
		cin >> n >> s0 >> s1;
		cout << solve(s0, s1) << endl;
	}
	return 0;
}