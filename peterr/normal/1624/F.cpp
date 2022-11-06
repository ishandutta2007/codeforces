#include <bits/stdc++.h>
 
using namespace std;

int query(int c)
{
	cout << "+ " << c << endl;
	int q;
	cin >> q;
	return q;
}

int main()
{
	int n;
	cin >> n;
	int lo = 1;
	int hi = n - 1;
	while (lo < hi)
	{
		int lower = lo / n;
		int mid = (lo + hi + 1) / 2;
		int add = n - mid % n;
		int q = query(add);
		if (q > lower)
		{
			lo = mid;
		}
		else
		{
			hi = mid - 1;
		}
		lo += add;
		hi += add;
	}
	cout << "! " << lo << endl;
	return 0;
}