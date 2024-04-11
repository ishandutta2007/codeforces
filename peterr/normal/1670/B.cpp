#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;

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
		set<int> indexes;
		for (int i = 0; i < n; i++)
		{
			indexes.insert(i);
		}
		int k;
		cin >> k;
		set<char> special;
		for (int i = 0; i < k; i++)
		{
			char ch;
			cin >> ch;
			special.insert(ch);
		}
		set<int> specialind;
		for (int i = 0; i < n; i++)
		{
			if (special.count(s[i]))
				specialind.insert(i);
		}
		int ans = 0;
		while (1)
		{
			vector<int> vec;
			for (int ind : specialind)
			{
				auto it = indexes.lower_bound(ind);
				if (it != indexes.begin())
				{
					vec.push_back(*(--it));
				}
			}
			if (vec.empty())
				break;
			for (int ind : vec)
			{
				indexes.erase(ind);
				specialind.erase(ind);
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}