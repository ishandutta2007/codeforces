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
	int x = 0, y = 0, cnt = 0;
	for (int i = 0; i < (s.size() - 1); ++i)
	{
		if (s[i] == 'U')
			y++;
		else if (s[i] == 'R')
			x++;
		if (x == y && s[i] == s[i + 1]) {
			cnt++;
		}
	}
	cout << cnt;
}