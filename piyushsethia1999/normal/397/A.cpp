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
	std::vector<int> r(n);
	vector<int> l(n); for (int o = 0; o < n; o++) { cin >> l[o] >> r[o]; }
	std::vector<int> t(100, 0);
	for (int i = 1; i < n; ++i)
	{
		for (int j = l[i]; j < r[i]; ++j)
		{
			t[j]++;
		}
	}
	print(t);
	int cnt = 0;
	for (int j = l[0]; j < r[0]; ++j)
	{
		if(!t[j])
			cnt++;
	}
	cout << cnt;
}