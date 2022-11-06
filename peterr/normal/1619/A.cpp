#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s.length() & 1)
			cout << "NO\n";
		else
			cout << (s.substr(0, s.length() / 2) == s.substr(s.length() / 2) ? "YES" : "NO") << "\n";
	}
	return 0;
}