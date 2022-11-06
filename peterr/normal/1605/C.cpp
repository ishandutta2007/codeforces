#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == 'a' && s[i + 1] == 'a')
			{
				cout << "2\n";
				goto done;
			}
		}
		for (int i = 0; i < n - 2; i++)
		{
			if (s[i] == 'a' && s[i + 2] == 'a')
			{
				cout << "3\n";
				goto done;
			}
		}
		for (int i = 0; i < n - 3; i++)
		{
			if (s[i] == 'a' && s[i + 3] == 'a' && s[i + 1] != s[i + 2])
			{
				cout << "4\n";
				goto done;
			}
		}
		for (int i = 0; i < n - 6; i++)
		{
			int cnt1 = 0;
			int cnt2 = 0;
			for (int j = 0; j < 7; j++)
			{
				if (s[i + j] == 'a')
				{
					cnt1++;
					cnt2++;
				}
				else if (s[i + j] == 'b')
					cnt1--;
				else
					cnt2--;
			}
			if (cnt1 > 0 && cnt2 > 0)
			{
				cout << "7\n";
				goto done;
			}
		}
		cout << "-1\n";
		done:;
	}
}