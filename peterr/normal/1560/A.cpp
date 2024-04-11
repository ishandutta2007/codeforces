#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		n--;
		int ans = 1;
		while (n)
		{
			ans++;
			n--;
			while (ans % 10 == 3 || ans % 3 == 0)
				ans++;
		}
		cout << ans << "\n";
	}
}