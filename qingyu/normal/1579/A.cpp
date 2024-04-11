#include <bits/stdc++.h>

using namespace std;

int c[1005];
string s;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		memset(c, 0, sizeof c);
		for (int i = 0; i < s.length(); ++i)
			++c[s[i]];
		puts(c['A'] + c['C'] == c['B'] ? "YES" : "NO");
	}
}