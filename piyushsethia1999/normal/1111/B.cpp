#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

long double eps = 1e-9;

int cmp(long double a) {
	if(a > eps)
		return 1;
	return 0;
}

long double maxi(long double a, long double b)
{
	if(cmp(a - b) == 1)
		return a;
	return b;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(16);
	int n; cin >> n;
	int k; cin >> k;
	int m; cin >> m;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	std::vector<int> pre(n + 1);
	pre[n] = 0;
	for (int i = n - 1; i >= 0; --i)
		pre[i] = pre[i + 1] + a[i];
	long double a1 = 0;
	for (int i = 0; i < min(m + 1, n); ++i)
	{
		int res = pre[i] + min(k * (n - i), m - i);
		long double aa = ((res * 1.0l) / (long double)(n - i));
		a1 = max(a1, aa);
	}
	cout << a1 << "\n";
}