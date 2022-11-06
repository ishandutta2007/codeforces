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
		int sum = 1000;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			sum += x;
		}
		if ((sum - n) % 2)
			cout << "errorgorn\n";
		else
			cout << "maomao90\n";
	}
	return 0;
}