#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long
#define r first
#define x second.first
#define y second.second

using namespace std;

bool ispar(pair<int, pair<int, int> > v1, pair<int, pair<int, int> > v2)
{
	int d2 = (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
	int d1 = (v2.r - v1.r) * (v2.r - v1.r);
	// print(d1, d2);
	return (d2 <= d1);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	std::vector<pair<int, pair<int, int> > > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].x >> v[i].y >> v[i].r;
	}
	sort(v.begin(), v.end());
	std::vector<int> p(n, -1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (ispar(v[i], v[j])) {
				p[i] = j;
				break;
			}
		}
	}
	std::vector<int> lev(n, 0);
	int totalarea = 0;
	for (int i = n - 1; i >= 0 ; --i)
		if (p[i] != -1)
			lev[i] = lev[p[i]] + 1;
	// print(p, lev);
	for (int i = 0; i < n; ++i)
	{
		// print(totalarea, v[i].r * v[i].r);
		if (lev[i] == 0)
			totalarea += v[i].r * v[i].r;
		else if (lev[i] % 2 == 0)
			totalarea -= v[i].r * v[i].r;
		else
			totalarea += v[i].r * v[i].r;
	}
	long double res = totalarea;
	long double pi = (long double)(3.14159265358979323846);
	res *= pi;
	cout << res;
}