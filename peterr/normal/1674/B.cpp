#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	map<pair<int, int>, int> mp;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i == j)
				continue;
			int num = (int) mp.size() + 1;
			mp[{i, j}] = num;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << mp[{s[0] - 'a', s[1] - 'a'}] << "\n";
	}
	return 0;
}