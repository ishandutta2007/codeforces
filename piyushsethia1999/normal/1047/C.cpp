#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
const int N = 15000001;
int lp[N + 1];
vector<int> pr;
void func() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	func();
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int gd = a[0];
	for (int i = 0; i < n; ++i)
		gd = __gcd(gd, a[i]);
	for (int i = 0; i < n; ++i)
		a[i] /= gd;
	int u = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != 1)
			u = 1;
	}
	if (u != 1)
	{
		cout << -1;
		return 0;
	}

	std::map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		while (a[i] != 1)
		{
			int lpp = lp[a[i]];
			m[lpp]++;
			while (a[i] % lpp == 0)
				a[i] /= lpp;
		}
	}
	int mi = 1000000;
	int fa = 1;
	for (auto y : m)
	{
		int f, nn;
		tie(f, nn) = y;
		if ((n - nn) < mi)
		{
			mi = n - nn;
			fa = f;
		}
	}
	cout << mi;
}