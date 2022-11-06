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
	string s; cin >> s;
	int in = (int)('a');
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == in)
			in++;
		else if (s[i] > in)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}