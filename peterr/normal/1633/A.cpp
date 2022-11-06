#include <bits/stdc++.h>
 
using namespace std;

int solve(int n)
{
	if (n % 7 == 0)
		return n;
	int m = n;
	while ((m + 1) % 10 != 0)
	{
		m++;
		if (m % 7 == 0)
			return m;
	}
	m = n;
	while ((m - 1) % 10 != 0)
	{
		m--;
		if (m % 7 == 0)
			return m;
	}
	return m;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}