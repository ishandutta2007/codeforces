#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool good = true;
		string ans = "";
		string prev = "";
		for (int i = 0; i < n - 2; i++)
		{
			string s;
			cin >> s;
			if (i)
			{
				if (prev[1] == s[0])
					ans += s[1];
				else
				{
					good = false;
					ans += s;
				}
			}
			else
			{
				ans = s;
			}
			prev = s;
		}
		if (good)
			ans += "a";
		cout << ans << "\n";
	}
	return 0;
}