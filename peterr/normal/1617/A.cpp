#include <bits/stdc++.h>
 
using namespace std;

int freq[26];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		bool hasA = false;
		bool hasB = false;
		bool hasC = false;
		fill(freq, freq + 26, 0);
		for (char ch : s)
		{
			freq[ch - 'a']++;
			if (ch == 'a')
				hasA = true;
			else if (ch == 'b')
				hasB = true;
			else if (ch == 'c')
				hasC = true;
		}
		if (!hasA || !hasB || !hasC || t[0] != 'a' || t[1] != 'b')
		{
			sort(s.begin(), s.end());
			cout << s << "\n";
		}
		else
		{
			for (int i = 0; i < freq[0]; i++)
				cout << 'a';
			for (int i = 0; i < freq[2]; i++)
				cout << 'c';
			for (int i = 0; i < freq[1]; i++)
				cout << 'b';
			for (int i = 3; i < 26; i++)
				for (int j = 0; j < freq[i]; j++)
					cout << (char) ('a' + i);
			cout << "\n";
		}
	}
	return 0;
}