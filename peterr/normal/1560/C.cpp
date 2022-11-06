#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		int col = 1;
		long long ub = 1;
		while (k > ub)
		{
			col++;
			ub += 2 * col - 1;
		}
		if (k >= ub - col + 1)
		{
			cout << col << " " << ub - k  + 1 << "\n";
		}
		else
		{
			cout << k - (ub - col) + col - 1 << " " << col << "\n";
		}	
	}
	return 0;
}