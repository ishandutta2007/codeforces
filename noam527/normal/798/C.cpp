#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y);

int n, a[100002], nexta = 0, op = 0, g = 0;

int gcd(int x, int y)
{
	if (x * y == 0)
		return max(x, y);
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		g = gcd(g, a[i]);
		a[i] = a[i] % 2;
	}
	cout << "YES\n";
	if (g > 1)
	{
		cout << "0";
		return 0;
	}
	while (nexta < n)
	{
		if (a[nexta] + a[nexta + 1] == 2)
		{
			op++;
			nexta++;
		}
		else if (a[nexta] == 1)
			op += 2;
		nexta++;
	}
	cout << op;
	return 0;
}