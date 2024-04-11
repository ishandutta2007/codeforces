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
		int zeros = 0;
		int ones = 0;
		for (char ch : s)
		{
			if (ch == '0')
				zeros++;
			else
				ones++;
		}
		if (zeros != ones)
		{
			cout << min(zeros, ones) << "\n";
		}
		else
		{
			cout << zeros - 1 << "\n";
		}
	}
	return 0;
}