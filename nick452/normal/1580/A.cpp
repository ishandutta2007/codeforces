#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& a, const vector<int>& b, int m) {
	assert(m >= 3);
	int ret = 1e9;
	int n = a.size();
	vector<int> sa(n + 1);
	for (int i = 0; i < n; ++i) {
		sa[i + 1] = sa[i] + a[i];
	}
	vector<int> sb(n + 1);
	for (int i = 0; i < n; ++i) {
		sb[i + 1] = sb[i] + b[i];
	}
	vector<int> f1(n);
	vector<int> f2(n);
	for (int i = 0; i < n; ++i) {
		f1[i] = m - a[i];
		f1[i] -= sa[i + 1];
		f1[i] -= 2 * i;
		f1[i] += sb[i + 1];
		f2[i] = m - a[i];
		f2[i] += sa[i];
		f2[i] += 2 * (i - 1);
		f2[i] -= sb[i];
	}
	for (int i = 1; i < n; ++i) {
		f1[i] = min(f1[i], f1[i - 1]);
	}
	for (int i = 3; i < n; ++i) {
		ret = min(ret, f2[i] + f1[i - 3]);
	}
	return ret;
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
		int n;
		int m;
		cin >> n >> m;
		vector<string> s(n);
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			for (int j = 0; j < m; j++) {
				a[i][j] = s[i][j] - '0';
			}
		}
		int ret = 1e9;
		for (int i = 0; i < n; i++) {
			vector<int> b(m);
			vector<int> c(m);
			for (int j = i + 1; j < n; j++) {
				if (j - i + 1 >= 5) {
					for (int k = 0; k < m; k++) {
						c[k] = a[i][k] + a[j][k];
					}
					ret = min(ret, solve(b, c, j - i - 1));
				}
				for (int k = 0; k < m; k++) {
					b[k] += a[j][k];
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}