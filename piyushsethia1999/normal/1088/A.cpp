#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int x; cin >> x;
	int a = -1;
	int b = -1;

	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= x; ++j)
		{
			if ((i % j == 0) && ((i / j) < x) && ((i * j) > x))
			{
				a = i;
				b = j;
			}
		}
	}
	if (a == -1)
	{
		cout << -1;
	}
	else
		cout << a << " " << b;
}