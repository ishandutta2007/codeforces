#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;



int main()
{
	ll k, n, m, a, b;
	int c1, c2, c3, c4;

	std::cin >> k;
	if (k % 2 == 0){ std::cout << "NO\n"; }
	else{

		n = 4 * k - 2;
		m = 2 * k*(k - 1) + 1 + k - 1;

		std::cout << "YES\n";
		std::cout << n << " " << m << "\n";


		int i = 1;

		for (c1 = 2; c1 <= k; c1++){ std::cout << 1 << " " << c1 << "\n"; }
		for (c1 = 2; c1 <= k; c1++){
			for (c2 = k + 1; c2 <= k + k - 1; c2++){

				std::cout << c1 << " " << c2 << "\n";

			}
		}

		for (c1 = k + 1; c1<k + k - 1; c1 += 2){

			std::cout << c1 << " " << c1 + 1 << "\n";

		}

		std::cout << 1 << " " << k + k << "\n";

		for (c1 = 2; c1 <= k; c1++){ std::cout << k + k << " " << c1 + k + k - 1 << "\n"; }
		for (c1 = 2; c1 <= k; c1++){
			for (c2 = k + 1; c2 <= k + k - 1; c2++){

				std::cout << c1 + k + k - 1 << " " << c2 + k + k - 1 << "\n";

			}
		}

		for (c1 = k + 1; c1<k + k - 1; c1 += 2){

			std::cout << c1 + k + k - 1 << " " << c1 + 1 + k + k - 1 << "\n";

		}





	}

	return 0;
}