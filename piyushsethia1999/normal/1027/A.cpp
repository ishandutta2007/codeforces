#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int modu(int a)
{
	if (a > 0)
		return a;
	return (-a);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int t; cin >> t;
	while (t--)
	{

		int n; cin >> n;
		string s; cin >> s;
		bool b = true;
		for (int i = 0; i < n; ++i)
		{
			if (modu(s[i] - s[n - i - 1]) != 2 && modu(s[i] - s[n - i - 1] != 0))
				b = false;
		}
		if (b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}