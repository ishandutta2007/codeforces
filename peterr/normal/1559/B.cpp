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
		int n;
		string s;
		cin >> n >> s;
		if (all_of(s.begin(), s.end(), [](char ch) {return ch == '?';}))
		{
			for (int i = 0; i < n; i++)
			{
				if (i & 1)
					cout << 'R';
				else
					cout << 'B';
			}
			cout << "\n";
			continue;
		}
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] != '?' && s[i + 1] == '?')
			{
				s[i + 1] = s[i] == 'R' ? 'B' : 'R';
			}
		}
		reverse(s.begin(), s.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] != '?' && s[i + 1] == '?')
			{
				s[i + 1] = s[i] == 'R' ? 'B' : 'R';
			}
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	return 0;
}