#include <bits/stdc++.h>

using namespace std;

bool solve(long long a, long long b, long long x)
{
	if (a == x || b == x)
		return true;
	if (a == 0 || b == 0 || a == b)
		return false;
	if (a < b)
		return solve(b, a, x);
	if (x > b && x < a && (a - x) % b == 0)
		return true;
	return solve(b, a % b, x);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, x;
		cin >> a >> b >> x;
		cout << (solve(a, b, x) ? "YES" : "NO") << "\n";
	}
	return 0;
}