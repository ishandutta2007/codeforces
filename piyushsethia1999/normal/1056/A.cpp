#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	set<int> s;
	int r; cin >> r;
	for (int i = 0; i < r; ++i)
	{
		int y; cin >> y;
		s.insert(y);
	}
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> r;
		set<int> s1;
		for (int j = 0; j < r; ++j)
		{
			int pp; cin >> pp;
			if (s.find(pp) != s.end())
			{
				s1.insert(pp);
			}
		}
		s = s1;
	}
	for (int i : s)
	{
		cout << i << " ";
	}
}