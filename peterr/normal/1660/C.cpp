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
		int ptr = 0;
		int ans = (int) s.length();
		while (ptr < (int) s.length())
		{
			set<char> st;
			while (ptr < (int) s.length())
			{
				if (st.count(s[ptr]))
				{
					ans -= 2;
					ptr++;
					break;
				}
				else
					st.insert(s[ptr++]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}