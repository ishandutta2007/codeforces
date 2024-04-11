#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int a, int b)
{
	vector<int> ans;
	int n = a + b;
	int zeros = (n + 1) / 2;
	int ones = n / 2;
	for (int i = 0; i <= a; i++)
	{
		int other = a - i;
		if (i > ones)
			continue;
		if (other > zeros)
			continue;
		ans.push_back(i + zeros - other);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		vector<int> ans;
		vector<int> vec1 = solve(a, b);
		vector<int> vec2 = solve(b, a);
		ans.insert(ans.end(), vec1.begin(), vec1.end());
		ans.insert(ans.end(), vec2.begin(), vec2.end());
		sort(ans.begin(), ans.end());
		ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
		cout << ans.size() << "\n";
		for (int x : ans)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}