#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n';
}

/*
	Si gcd(a + x, m) = gcd(a, m). On a gcd(a, m) | x. Donc on peut tout diviser par gcd(a,m) et obtenir:
	gcd(a, m) = gcd(a+x, m) = 1. Donc si d | m, a != -x mod m
	Il faut a + x premier avec m donc 
*/

ll solve(void)
{
	ll a, m;
	cin >> a >> m;
	ll g = gcd(a,m);
	a /= g, m /= g;

	ll phi(1);
	for (ll p(2); p*p<= m; ++p)
		if (m%p==0)
		{
			ll q = 1;
			while (m%p==0)
			{
				q *= p;
				m /= p;
			}
			phi *= q-q/p;
		}
	if (m>1)
		phi *= m-1;
	return phi;
}