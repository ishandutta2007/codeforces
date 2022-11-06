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
	string s; cin >> s;
	string s1; cin >> s1;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != s1[i])
		{
			if (i < n - 1 && s[i + 1] != s1[i + 1] && s[i + 1] != s[i])
			{
				cnt ++;
				i++;
			}
			else
				cnt++;
		}
	}
	cout << cnt;
}