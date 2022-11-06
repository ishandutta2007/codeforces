#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		string s, t;
		cin >> s >> t;
		if (t.length() == 1)
		{
			if (t == "a")
				cout << "1\n";
			else
				cout << (1LL << s.length()) << "\n";
		}
		else
		{
			bool found = false;
			for (char ch : t)
			{
				if (ch == 'a')
					found = true;
			}
			if (found)
				cout << "-1\n";
			else
				cout << (1LL << s.length()) << "\n";
		}
	}
	return 0;
}