#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		if (!a)
			cout << "1\n";
		else
			cout << 2 * b + a + 1 << "\n";
	}
	return 0;
}