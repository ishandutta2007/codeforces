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
		s = "x" + s + "x";
		bool ans = true;
		for (int i = 1; i < (int) s.length() - 1; i++)
		{
			if (s[i] != s[i - 1] && s[i] != s[i + 1])
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}