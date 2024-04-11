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

ll asci(char c){

	return (int(c) - 97);

}

int main()
{
	ll k, z, n, m, a, b, c;
	ll c1, c2, c3, c4, c5, c6, c7;
	
	std::map <ll, ll> M;
	std::vector <ll> v;
	std::vector <ll> C;

	for (c1 = 0; c1 < 26; c1++){

		std::cin >> a;
		v.push_back(a);

	}

	std::string S;

	std::cin >> S;
	n = S.length();
	c2 = 0;
	ll ans = 0;
	for (c1 = 0; c1 < n; c1++){

		C.push_back(c2 + v[asci(S[c1])]);
		//cout << C[c1] << " ";
		c2 = C[c1];
		if (C[c1] < 0){

			a = C[c1] * 10000000ll - asci(S[c1]);
			

		}
		else{ a = C[c1] * 10000000ll + asci(S[c1]); }

		if (C[c1] - v[asci(S[c1])] < 0){ b = (C[c1] - v[asci(S[c1])]) * 10000000ll - asci(S[c1]); }
		else{ b = (C[c1] - v[asci(S[c1])]) * 10000000ll + asci(S[c1]); }

		if (M.find(b) != M.end()){ ans += M[b]; }

		if (M.find(a) == M.end()){ M[a] = 1; }
		else{ M[a]++; }

		


	}

	std::cout << ans << "\n";
	

	return 0;
}