#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (b + b - a > 0 && (b + b - a) % c == 0)
		{
			cout << "YES\n";
			continue;
		}
		if (b + b - c > 0 && (b + b - c) % a == 0)
		{
			cout << "YES\n";
			continue;
		}
		if (a + b > 0 && (a + c) % 2 == 0 && (a + c) / 2 % b == 0)
		{
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}