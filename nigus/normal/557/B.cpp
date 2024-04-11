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
	ll k, z, n, m, x, y, a, b, c, w;
	int c1, c2, c3, c4, c5, c6, c7;


	std::cin >> n >> w;

	std::vector<ll> A;

	for (c1 = 0; c1 < 2 * n; c1++){

		std::cin >> a;
		A.push_back(a);



	}

	std::sort(A.begin(), A.end());

	x = A[0];
	y = A[n];

	long double ans = 0;

	if (2 * x < y){

		ans = 3 * x*n;
	}
	else{

		ans = 1.5*y*n;


	}
	if (ans>w){ans = w;
}
	std::cout << fixed << setprecision(9) << ans << "\n";
	return 0;
}