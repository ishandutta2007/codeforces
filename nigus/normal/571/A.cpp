#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

ll big = 1000000007ll;

ll f(ll m, ll l)
{
	ll a = 0;
	if (m>l){  a += round((l+1)*(l+2)/ 2); }
	else{ a += round(((m+2)*(m+1)) / 2); }
	return a;

}

int main()
{

	ll c1, c2, c3, c4, c5, c6, c7, t;
	ll k, z, a, b, ans, q, x, y, c, l, r, n, m, i;

	std::cin >> a >> b >> c >> l;

	x = l + 1;
	ans = round((l+1)*(l+2)*(l+3)/6);
	ll l2;


	i = b + c - a;
	m = 0;
	
	if (i < 0){ m = -i; i = 0; }

	if (i <= l)
	{
		for (c1 = i; c1 <= l; c1++)
		{
			l2 = l - c1;
			ans -= f(m, l2);
			m++;

		}


	}


	i = a + c - b;
	m = 0;
	if (i < 0){ m = -i; i = 0; }

	if (i <= l)
	{
		for (c1 = i; c1 <= l; c1++)
		{
			l2 = l - c1;
			ans -= f(m, l2);
			m++;
		}


	}

	i = a + b - c;
	m = 0;
	if (i < 0){ m = -i; i = 0; }

	if (i <= l)
	{
		for (c1 = i; c1 <= l; c1++)
		{
			l2 = l - c1;
			ans -= f(m, l2);
			m++;
		}


	}
	if (ans < 0){ ans = 0; }
	std::cout << ans << "\n";

	return 0;
}