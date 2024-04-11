#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(int n, int m, vector<int> a) {
	map<int, vector<int>> vals;
	for (int i = n * m - 1; i >= 0; --i) {
		vals[a[i]].push_back(i);
	}
	vector<int> r;
	for (const auto& w : vals) {
		vector<int> p = w.second;
		while (p.size() > 0) {
			int count = min<int>(p.size(), m - r.size() % m);
			int at = p.size() - count;
			r.insert(r.end(), p.begin() + at, p.end());
			p.resize(at);
		}
	}
	int ret = 0;
	for (int row = 0; row < n * m; row += m) {
		for (int i = row; i < row + m; ++i) {
			for (int j = row; j < i; ++j) {
				if (r[i] > r[j]) {
					++ret;
				}
			}
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n * m);
		for (int i = 0; i < n * m; ++i) {
			cin >> a[i];
		}
		cout << solve(n, m, a) << endl;
	}
	return 0;
}