#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

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
	std::vector<int> ch(26, 0);
	for (int i = 0; i < s.size(); ++i)
		ch[(s[i] - 'a')]++;
	int cnt = 0;
	int c1 = 0;
	print(ch);
	for (int i = 0; i < 26; ++i)
	{
		if (ch[i] == 1)
			cnt++;
		else if (ch[i] > 1)
			c1++;
	}
	if (c1)
		cout << "Yes";
	else if (cnt > 1)
		cout << "No";
	else
		cout << "Yes";
}