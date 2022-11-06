#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		bool r = false;
		bool g = false;		
		bool b = false;		
		bool ans = true;
		for (char ch : s)
		{
			if (ch == 'r')
				r = true;
			if (ch == 'g')
				g = true;				
			if (ch == 'b')
				b = true;				
			if (ch == 'R' && !r)
				ans = false;
			if (ch == 'G' && !g)
				ans = false;
			if (ch == 'B' && !b)
				ans = false;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}