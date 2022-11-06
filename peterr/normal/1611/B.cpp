#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b, int k)
{
	if (a < k)
		return false;
	if (b < k)
		return false;
	if (2 * k > a + b - 2 * k)
		return false;
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int lo = 0;
		int hi = 1E9;
		while (lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if (check(a, b, mid))
				lo = mid;
			else
				hi = mid - 1;
		}
		cout << lo << "\n";
	}	
			
	return 0;
}