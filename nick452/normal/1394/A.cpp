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
	int n, d, m;
	cin >> n >> d >> m;
	vector<long long> a, b;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p <= m)
			a.push_back(p);
		else
			b.push_back(p);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	n = a.size();
	m = b.size();
	vector<long long> sa(n + 1);
	vector<long long> sb(m + 1);
	for (int i = 0; i < n; i++) {
		sa[i + 1] = sa[i] + a[i];
	}
	for (int i = 0; i < m; i++) {
		sb[i + 1] = sb[i] + b[i];
	}
	long long result = sa[n];
	for (int i = 1; i <= m && i + (i - 1) * d <= n + m; i++) {
		result = max(result, sb[i] + sa[min(n, n + m - (i + (i - 1) * d))]);
	}
	cout << result << endl;
	return 0;
}