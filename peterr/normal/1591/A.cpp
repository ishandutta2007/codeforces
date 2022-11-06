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
		bool dead = false;
		int prev = 1;
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (i)
			{
				if (x)
				{
					if (prev)	
						ans += 5;
					else
						ans++;
				}
				else
				{
					if (!prev)
						dead = true;
				}
			}
			else
			{
				ans += x;
			}
			prev = x;
		}
		if (dead)
			ans = -1;
		cout << ans << "\n";
	}
}