#include <bits/stdc++.h>
 
using namespace std;

string doit(string s, int ind)
{
	string ans = "";
	for (int i = 0; i < (int) s.length(); i++)
	{
		if (i == ind)
		{
			int x = s[i] - '0';
			int y = s[i + 1] - '0';
			ans += to_string(x + y);
			i++;
		}
		else
		{
			ans += s[i];
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int found = -1;
		for (int i = (int) s.length() - 2; i >= 0; i--)
		{
			int x = s[i] - '0';
			int y = s[i + 1] - '0';
			if (x + y >= 10)
			{
				found = i;
				break;
			}
		}
		string ans = "";
		if (found == -1)
			ans = doit(s, 0);
		else
			ans = doit(s, found);
		cout << ans << "\n";
	}
	return 0;
}