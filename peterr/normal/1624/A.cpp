#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int mn = 1E9;
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		cout << mx - mn << "\n";
	}
	return 0;
}