#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x = i + j;
				x = max(x, i + (m - j - 1));
				x = max(x, (n - i - 1) + j);
				x = max(x, (n - i - 1) + (m - j - 1));
				vec.push_back(x);
			}
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < (int) vec.size(); i++)
		{
			cout << vec[i] << " \n"[i == (int) vec.size() - 1];
		}
	}
	return 0;
}