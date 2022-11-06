#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (y % x)
			cout << "0 0\n";
		else
			cout << "1 " << y / x << "\n";
	}
	return 0;
}