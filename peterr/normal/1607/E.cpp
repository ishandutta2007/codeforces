#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &vec, int n)
{
	int mn = 0;
	int mx = 0;
	int pos = 0;
	for (int i : vec)
	{
		pos += i;
		if (pos - mn >= n || mx - pos >= n)
		{
			break;
		}
		mx = max(pos, mx);
		mn = min(pos, mn);
	}
	return 1 - mn;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> vec1;
		vector<int> vec2;
		for (char ch : s)
		{
			if (ch == 'L')
				vec1.push_back(-1);
			if (ch == 'R')
				vec1.push_back(1);
			if (ch == 'U')
				vec2.push_back(-1);
			if (ch == 'D')
				vec2.push_back(1);
		}
		int c = solve(vec1, m);
		int r = solve(vec2, n);
		cout << r << " " << c << "\n";
	}
	return 0;
}