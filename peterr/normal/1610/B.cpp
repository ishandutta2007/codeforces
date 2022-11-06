#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;

bool check(vector<int> a)
{
	int n = (int) a.size();
	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] != a[n - i - 1])
			return false;
	}
	return true;
}

vector<int> rem(vector<int> vec, int x)
{
	vector<int> ans;
	for (int y : vec)
		if (y != x)
			ans.push_back(y);
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool ans = true;
		for (int i = 0; i < n / 2; i++)
		{
			if (a[i] != a[n - i - 1])
			{
				ans = false;
				if (check(rem(a, a[i])))
					ans = true;
				if (check(rem(a, a[n - i - 1])))
					ans = true;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}