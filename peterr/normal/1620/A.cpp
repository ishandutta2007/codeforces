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
		cout << (count(s.begin(), s.end(), 'N') == 1 ? "NO" : "YES") << "\n";
	}
	return 0;
}