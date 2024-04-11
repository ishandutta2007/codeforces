#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < 2; i++)
		{
			int k;
			cin >> k;
			vector<int> vec;
			while (k--)
			{
				int x;
				cin >> x;
				vec.push_back(x);
			}
			ans = max(ans, (long long) (vec.back() - vec[0]) * h);
		}
		for (int i = 0; i < 2; i++)
		{
			int k;
			cin >> k;
			vector<int> vec;
			while (k--)
			{
				int x;
				cin >> x;
				vec.push_back(x);
			}
			ans = max(ans, (long long) (vec.back() - vec[0]) * w);
		}
		cout << ans << "\n";
	}
	return 0;
}