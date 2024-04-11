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
	int aa = 0, bb = 0;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; aa ^= a[o];}
	vector<int> b(n); for (int o = 0; o < n; o++) { cin >> b[o]; bb ^= b[o];}
	std::vector<int> res(n);
	int pos[2];
	int g = 0;
	std::vector<int> pos1(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == b[i]) {
			res[i] = a[i];
			pos1[a[i]]++;
		}
		else
			pos[g++] = i;
	}
	// print(g);
	if (g == 2)
	{
		int i1 = pos[0];
		int i2 = pos[1];
		if (!pos1[a[i1]] && !pos1[b[i2]])
		{
			res[i1] = a[i1];
			res[i2] = b[i2];
		}
		else
		{
			res[i1] = b[i1];
			res[i2] = a[i2];
		}
	}
	else if (g == 1) {
		for (int i = 1; i <= n; ++i)
		{
			if (pos1[i] == 0)
			{
				res[pos[0]] = i;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}
}