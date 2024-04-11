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


int main()
{
	ll k, z, n, m, a, b, c;
	ll c1, c2, c3, c4, c5, c6, c7;
	ll h1, h2;
	std::set<ll> u;
	std::set<ll> v;

	std::cin >> n >> m;
	ll tot = 0;
	std::cin >> h1;
	for (c1 = 0; c1 < h1; c1++){

		std::cin >> a;
		u.insert(a);
		tot++;
	}

	std::cin >> h2;
	for (c1 = 0; c1 < h2; c1++){

		std::cin >> a;
		v.insert(a);
		tot++;
	}

	ll ma = max(n, m)+3;

	ma = ma*ma;
	c = 0;
	while (c < ma){

		a = c%n;
		b = c%m;

		if (u.find(a) != u.end() && v.find(b) == v.end()){ v.insert(b); tot++;}
		if (v.find(b) != v.end() && u.find(a) == u.end()){ u.insert(a); tot++;}
		c++;

	}
	//std::cout << tot << " ";
	if (tot >= n + m){ std::cout << "Yes\n"; }
	else{ std::cout << "No\n"; }
	return 0;
}