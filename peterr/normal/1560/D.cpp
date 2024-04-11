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
		int ans = 1E8;
		string s1 = to_string(n);
		for (int i = 0; i < 63; i++)
		{
			long long two = 1LL << i;
			string s0 = to_string(two);
			int cnt = (int) s0.length() + (int) s1.length();
			int ptr = 0;
			for (int j = 0; j < (int) s0.length(); j++)
			{
				while (ptr < (int) s1.length() && s1[ptr] != s0[j])
					ptr++;
				if (ptr >= (int) s1.length())
					break;
				cnt -= 2;
				ptr++;
			}
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}