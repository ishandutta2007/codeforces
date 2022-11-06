#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int bal = 0;
			int groups = 0;
			int streak = 0;
			for (int j = i; j < n; j++)
			{
				if (s[j] == '+')
				{
					bal++;
					streak = 0;
				}
				else
				{
					bal--;
					streak++;
					if (streak % 2 == 0)
						groups++;
				}
				if (bal <= 0 && bal % 3 == 0 && abs(bal / 3) <= groups)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}