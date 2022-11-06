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
		int ones = 0;
		for (char ch : s)
			ones += ch == '1';
		bool sorted = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] > s[i + 1])
				sorted = false;
		}
		if (sorted)
			cout << "0\n";
		else
		{
			cout << "1\n";
			vector<int> ans;
			for (int i = 0; i < n; i++)
			{
				if (n - i <= ones)
				{
					if (s[i] == '0')
						ans.push_back(i + 1);
				}
				else
				{
					if (s[i] == '1')
						ans.push_back(i + 1);
				}
				
			}
			cout << ans.size() << " ";
			for (int x : ans)
				cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}