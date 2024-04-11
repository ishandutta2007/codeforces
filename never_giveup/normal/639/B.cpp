#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	#ifdef ONPC
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	int n, d, h;
	cin >> n >> d >> h;
	if (d == 1)
	{
		if (n > 2)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << "1 2" << endl;
		}
		return 0;
	}
	if (d == h)
	{
		int cur = 2;
		while (cur <= h + 1)
		{
			cout << cur - 1 << " " << cur << endl;
			cur++;
		}
		while (cur <= n)
		{
			cout << 2 << " " << cur << endl;
			cur++;
		}
		return 0;
	}
	if (d > 2 * h)
	{
		cout << -1 << endl;
		return 0;
	}
	int cur = 2;
	for (int i = 0; i < h; i++)
	{
		cout << cur - 1 << " " << cur << endl;
		cur++;
	}
	if (cur <= d + 1)
	{
		cout << 1 << " " << cur << endl;
		cur++;
	}
	while (cur <= d + 1)
	{
		cout << cur - 1 << " " << cur << endl;
		cur++;
	}
	while (cur <= n)
	{
		cout << 1 << " " << cur << endl;
		cur++;
	}
	return 0;
}