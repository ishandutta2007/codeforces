#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		cout << ((x + z - 2 * y) % 3 == 0 ? 0 : 1) << "\n";
	}
	return 0;
}