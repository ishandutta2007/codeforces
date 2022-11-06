#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s1, s; cin >> s;
	s1 = "";
	string s2 = "p";
	while (s != "") {

		if (s.size() & 1)
		{
			s2[0] = s[0];
			s = s.substr(1, s.size() - 1);
			s1 += s2;
		}
		else
		{
			s2[0] = s[s.size() - 1];
			s = s.substr(0, s.size() - 1);
			s1 += s2;
		}
	}
	reverse(s1.begin(), s1.end());
	cout << s1;
}