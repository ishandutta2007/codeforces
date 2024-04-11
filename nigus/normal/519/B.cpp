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
	int c1, c2, c3, c4, c5, c6, c7;
	std::cin >> n;
	std::vector<ll> A;
	std::vector<ll> B;
	std::vector<ll> C;
	for (c1 = 0; c1 < n; c1++){

		std::cin >> a;
		A.push_back(a);

	}

	for (c1 = 0; c1 < n-1; c1++){

		std::cin >> a;
		B.push_back(a);
	}

	for (c1 = 0; c1 < n-2; c1++){

		std::cin >> a;
		C.push_back(a);
	}

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::sort(C.begin(), C.end());
	ll ans1 = -1;
	for (c1 = 0; c1 < n - 1; c1++){
		
		if (A[c1] != B[c1]){ ans1 = A[c1]; break; }


	}if (ans1 == -1){ ans1 = A[n - 1]; }

	ll ans2 = -1;
	for (c1 = 0; c1 < n - 2; c1++){

		if (B[c1] != C[c1]){ ans2 = B[c1]; break; }


	}if (ans2 == -1){ ans2 = B[n - 2]; }

	std::cout << ans1 << "\n" << ans2 << "\n";
	

	return 0;
}