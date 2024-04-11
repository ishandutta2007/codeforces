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
		string s;
		cin >> n >> s;
		string t = s;
		sort(t.begin(), t.end());
		int ans = 0;
		for (int i = 0; i < (int) s.length(); i++)
		{
			ans += (s[i] != t[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}