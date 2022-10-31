#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(int n, int m, vector<int> a) {
	assert(n == 1);
	vector<int> p(m);
	for (int i = 0; i < m; ++i) {
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y] || a[x] == a[y] && x > y; });
	ll ret = 0;
	vector<int> s(m + 1);
	for (int i = 0; i < m; ++i) {
		for (int k = p[i] + 1; k > 0; k &= (k - 1)) {
			ret += s[k];
		}
		for (int k = p[i] + 1; k <= m; k = (k | (k - 1)) + 1) {
			++s[k];
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