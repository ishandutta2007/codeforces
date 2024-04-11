#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = (int) s.length();
		int ans = 2;
		if (!any_of(s.begin(), s.end(), [&] (char ch) { return ch == '0'; }))
			ans = min(ans, 0);
		if (any_of(s.begin(), s.end(), [&] (char ch) { return ch == '0'; }))
		{
			int ind1 = s.find("0");
			int ind2 = s.rfind("0");
			bool noones = true;
			for (int i = ind1; i <= ind2; i++)
			{
				if (s[i] == '1')
				{
					noones = false;
					break;
				}
			}
			if (noones)
				ans = min(ans, 1);
		}
		cout << ans << "\n";
	}
	return 0;
}