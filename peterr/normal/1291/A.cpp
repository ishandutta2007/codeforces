#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		bool parity = 0;
		for (int i = 0; i < n; i++)
		{
			int key = s[i] - '0';
			if (key % 2 != 0)
				parity = !parity;
		}
		int ptr = n - 1;
		while (ptr >= 0 && (s[ptr] - '0') % 2 == 0)
			ptr--;
		if (ptr <= 0)
			cout << -1 << endl;
		else
		{
			int a = s[ptr] - '0';
			ptr--;
			while (ptr >= 0 && (s[ptr] - '0') % 2 == 0)
				ptr--;
			if (ptr < 0)
				cout << -1 << endl;
			else
				cout << s[ptr] << a << endl;
		}
	}
	return 0;
}