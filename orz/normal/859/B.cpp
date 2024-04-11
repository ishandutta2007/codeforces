#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define ld long double

using namespace std;
int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll s, m = 1e9;
	cin >> s;
	for (int i = 1; i <= s; ++i)
	{
		ll t = 2 * (i + (s + i - 1) / i);
		if (t < m)
			m = t;
	}
	cout << m;
	return 0;
}