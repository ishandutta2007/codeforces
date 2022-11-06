#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	vector<int> a(n + 1); for (int o = 1; o <= n; o++) { cin >> a[o]; }
	set<int> s;
	bool f = true;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == i)
			s.insert(i);
		else if (a[a[i]] != a[i])
			f = false;
	}
	if (!f)
	{
		cout << -1;
		return 0;
	}
	int m = s.size();
	std::vector<int> g(n + 1);
	std::vector<int> h(m + 1);
	int cnt = 1;
	for (int a : s) {
		g[a] = cnt;
		h[cnt++] = a;
	}
	for (int i = 1; i <= n; ++i)
		g[i] = g[a[i]];
	cout << m << "\n";
	for (int i = 1; i <= n ; ++i)
		cout << g[i] << " ";
	cout << "\n";
	for (int i = 1; i <= m ; ++i)
		cout << h[i] << " ";
}