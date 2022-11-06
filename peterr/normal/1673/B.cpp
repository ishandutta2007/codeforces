#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		set<char> seen;
		vector<char> vec;
		bool repeat = false;
		bool ans = true;
		int n = 0;
		int cur = 0;
		for (int i = 0; i < (int) s.length(); i++)
		{
			char ch = s[i];
			if (seen.count(ch))
			{
				repeat = true;
				if (ch != vec[cur])
					ans = false;
				cur++;
				if (cur == n)
					cur = 0;
			}
			else
			{
				if (repeat)
					ans = false;
				seen.insert(ch);
				vec.push_back(ch);
				n++;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}