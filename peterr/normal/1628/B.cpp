#include <bits/stdc++.h>
 
using namespace std;

bool found2[26][26];
bool found3[26][26][26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 26; i++)
		{
			fill(found2[i], found2[i] + 26, false);
			for (int j = 0; j < 26; j++)
			{
				fill(found3[i][j], found3[i][j] + 26, false);
			}
		}
		int n;
		cin >> n;
		bool ans = false;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (s.size() == 1)
				ans = true;
			else if (s.size() == 2)
			{
				if (s[0] == s[1])
					ans = true;
				int a = s[0] - 'a';
				int b = s[1] - 'a';
				if (found2[b][a])
					ans = true;
				found2[a][b] = true;
				for (int j = 0; j < 26; j++)
					if (found3[b][a][j])
						ans = true;
			}
			else
			{
				if (s[0] == s[2])
					ans = true;
				int a = s[0] - 'a';
				int b = s[1] - 'a';
				int c = s[2] - 'a';
				if (found3[c][b][a])
					ans = true;
				if (found2[c][b])
					ans = true;
				found3[a][b][c] = true;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}