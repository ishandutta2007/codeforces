#include <bits/stdc++.h>

using namespace std;

int solve(int x1, int p1, int x2, int p2)
{
	if (p1 > p2)
		return -solve(x2, p2, x1, p1);
	p2 -= p1;
	p1 = 0;
	while (p2)
	{
		x2 *= 10;
		p2--;
		if (x2 > x1)
			return -1;
	}
	if (x1 < x2)
		return -1;
	if (x1 > x2)
		return 1;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x1, p1, x2, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		int ans = solve(x1, p1, x2, p2);
		if (ans == 1)
			cout << ">\n";
		else if (ans == -1)
			cout << "<\n";
		else
			cout << "=\n";
	}
	return 0;
}