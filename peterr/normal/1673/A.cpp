#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.length() == 1)
			cout << "Bob " << s[0] - 'a' + 1 << "\n";
		else
		{
			int sum = 0;
			for (char ch : s)
			{
				sum += ch - 'a' + 1;
			}
			int ans = sum;
			if (s.length() % 2 == 1)
			{
				ans -= s[0] - 'a' + 1;
				ans = max(ans, ans + (s[0] - 'a' + 1) - (s[(int) s.length() - 1] - 'a' + 1));
			}
			ans = ans - (sum - ans);
			cout << "Alice " << ans << "\n";
		}
	}
	return 0;
}