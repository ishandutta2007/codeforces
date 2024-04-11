#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve_one_case()
{
	int n, p, d;
	cin >> n >> p >> d;
	--p;
	string a;
	cin >> a;
	int x, y;
	cin >> x >> y;
	vector<int> f(n);
	for (int i = n - 1; i >= 0; --i) {
		f[i] = (a[i] == '0' ? x : 0);
		if (i + d < n) {
			f[i] += f[i + d];
		}
	}
	int results = std::numeric_limits<int>::max();
	for (int i = 0; i < n; ++i) {
		if (i + p < n) {
			results = min(results, y * i + f[i + p]);
		}
	}
	cout << results << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (; t > 0; --t) solve_one_case();
	return 0;
}