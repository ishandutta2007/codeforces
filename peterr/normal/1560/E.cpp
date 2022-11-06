#include <bits/stdc++.h>

using namespace std;

int freq[26];
int lastOcc[26];
int when[26];
bool del[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		fill(lastOcc, lastOcc + 26, -1);
		fill(freq, freq + 26, 0);
		fill(del, del + 26, false);
		string s;
		cin >> s;
		for (int i = 0; i < (int) s.length(); i++)
		{
			int key = s[i] - 'a';
			freq[key]++;
			lastOcc[key] = i;
		}
		vector<pair<int, int>> vec;
		for (int i = 0; i < 26; i++)
		{
			if (lastOcc[i] == -1)
				continue;
			vec.push_back({lastOcc[i], i});
		}
		sort(vec.begin(), vec.end());
		string b = "";
		for (int i = 0; i < (int) vec.size(); i++)
		{
			when[vec[i].second] = i;
			b += (char) ('a' + vec[i].second);
		}
		bool valid = true;
		int sum = 0;
		for (int i = 0; i < 26; i++)
		{
			if (lastOcc[i] == -1)
				continue;
			if (freq[i] % (when[i] + 1) != 0)
				valid = false;
			freq[i] /= when[i] + 1;
			sum += freq[i];
		}
		string a = s.substr(0, sum);
		string test = "";
		for (int i = 0; i < (int) vec.size(); i++)
		{
			for (char ch : a)
			{
				if (del[ch - 'a'])
					continue;
				test += ch;
			}
			del[vec[i].second] = true;
		}
		if (test != s)
			valid = false;
		if (!valid)
		{
			cout << "-1\n";
			continue;
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}