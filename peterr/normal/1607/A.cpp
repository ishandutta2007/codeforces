#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string keyboard, s;
		cin >> keyboard >> s;
		map<char, int> where;
		for (int i = 0; i < 26; i++)
		{
			where[keyboard[i]] = i;
		}
		int ans = 0;
		for (int i = 0; i < (int) s.length() - 1; i++)
		{
			ans += abs(where[s[i]] - where[s[i + 1]]);
		}
		cout << ans << "\n";
	}
	return 0;
}