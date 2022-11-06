#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int a, int b)
{
	bool greater = a > b;
	vector<int> ans = {1};
	deque<int> d;
	for (int i = 2; i <= n; i++)
		d.push_back(i);
	while (a)
	{
		ans.push_back(d.back());
		d.pop_back();
		if (b)
		{
			ans.push_back(d.front());
			d.pop_front();
			b--;
		}
		a--;
	}
	while (d.size())
	{
		if (greater)
		{
			ans.push_back(d.back());
			d.pop_back();
		}
		else
		{
			ans.push_back(d.front());
			d.pop_front();
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		if (abs(a - b) > 1 || a + b > n - 2)
		{
			cout << "-1\n";
		}
		else
		{
			vector<int> ans;
			if (b > a)
			{
				ans = solve(n, b, a);
				for (int &x : ans)
					x = n - x + 1;
			}
			else
				ans = solve(n, a, b);
			for (int x : ans)
				cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}