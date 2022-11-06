#include <bits/stdc++.h>

using namespace std;

bool even(char ch)
{
	return (ch - '0') % 2 == 0;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (even(s.back()))
			cout << "0\n";
		else if (even(s[0]))
			cout << "1\n";
		else
		{
			for (char ch : s)
			{
				if (even(ch))
				{
					cout << "2\n";
					goto stop;
				}
			}
			cout << "-1\n";
			stop:;
		}
	}
}