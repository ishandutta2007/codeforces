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
	ll k, z, n, m, x, y, a, b, c;
	int c1, c2, c3, c4, c5, c6, c7;
	string s;

	ll A, G, C, T;
	std::vector<ll> dna;
	A = 0;
	G = 0;
	C = 0;
	T = 0;
	std::cin >> n;
	std::cin >> s;
	
	for (c1 = 0; c1 < n; c1++){

		if (s[c1] == 'A'){ A++; }
		if (s[c1] == 'G'){ G++; }
		if (s[c1] == 'C'){ C++; }
		if (s[c1] == 'T'){ T++; }

	}
	dna.push_back(A);
	dna.push_back(G);
	dna.push_back(C);
	dna.push_back(T);
	ll ma=0;
	for (c1 = 0; c1 < 4; c1++){

		if (dna[c1] > ma){ ma = dna[c1]; }

	}
	m = 0;
	for (c1 = 0; c1 < 4; c1++){

		if (dna[c1] == ma){ m++; }

	}

	ll big = 1000000007ll;
	ll ans = 1;
	for (c1 = 0; c1 < n; c1++){

		ans *= m;
		ans %= big;

	}

	std::cout << ans << "\n";
	
	return 0;
}