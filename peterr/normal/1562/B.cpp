#include <bits/stdc++.h>

using namespace std;

int freq[10];

string solve(string& s)
{
	fill(freq, freq + 10, 0);
	string t;
	for (char ch : s)
	{
		freq[ch - '0']++;
		if (ch == '1' || ch == '4' || ch == '6' || ch == '8' || ch == '9')
			return "" + string(1, ch);
		t += ch;
	}
	if (freq[2] >= 2)
		return "22";
	if (freq[3] >= 2)
		return "33";
	if (freq[5] >= 2)
		return "55";
	if (freq[7] >= 2)
		return "77";
	for (int i = 0; i < (int) t.length(); i++)
	{
		for (int j = i + 1; j < (int) t.length(); j++)
		{
			int dig1 = t[i] - '0';
			int dig2 = t[j] - '0';
			int num = dig1 * 10 + dig2;
			bool isPrime = true;
			for (int k = 2; k < num; k++)
			{
				if (num % k == 0)
					isPrime = false;
			}
			if (!isPrime)
			{
				return to_string(num);
			}
		}
	}
	return t;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		string s;
		cin >> k >> s;
		string ans = solve(s);
		cout << ans.length() << "\n";
		cout << ans << "\n";
	}	
	return 0;
}