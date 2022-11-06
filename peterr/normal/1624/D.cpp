#include <bits/stdc++.h>
 
using namespace std;

int freq[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		string s;
		cin >> n >> k >> s;
		fill(freq, freq + 26, 0);
		for (char ch : s)
			freq[ch - 'a']++;
		int twos = 0;
		int ones = 0;
		for (int i = 0; i < 26; i++)
		{
			twos += freq[i] / 2;
			ones += freq[i] & 1;
		}
		int ans = 0;
		while (true)
		{
			if ((ans + 1) / 2 * k > twos)
				break;
			int remTwos = twos - (ans + 1) / 2 * k;
			if ((ans + 1) % 2 == 1 && k > remTwos * 2 + ones)
				break;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}