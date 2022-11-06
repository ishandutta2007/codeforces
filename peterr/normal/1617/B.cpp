#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n & 1)
		{
			int a = (n - 1) / 2 + 1;
			int b = (n - 1) / 2 - 1;
			if (a % 2 == 0)
			{
				a++;
				b--;
			}
			cout << a << " " << b << " " << 1 << "\n";
		}
		else
		{
			cout << 2 << " " << n - 3 << " " << 1 << "\n";
		}
	}
	return 0;
}