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
		int cur;
		cin >> cur;
		cur++;
		bool ans = true;
		for (int i = 1; i < n; i++)
		{
			int x;
			cin >> x;
			if (x != cur && x != cur + 1 && x != cur + 2)
				ans = false;
			cur++;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}