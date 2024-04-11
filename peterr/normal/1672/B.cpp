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
		int n = (int) s.length();
		if (s[0] == 'B' || s[n - 1] == 'A')
			cout << "NO\n";
		else
		{
			bool valid = true;
			int bal = 0;
			for (int i = 0; i < n; i++)
			{
				if (s[i] == 'A')
					bal++;
				else
					bal--;
				if (bal < 0)
					valid = false;
			}
			cout << (valid ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}