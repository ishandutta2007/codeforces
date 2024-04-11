#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;





int main()
{
	ll k, z, n, m, x, y, a, b, c,d;
	int c1, c2, c3, c4, c5, c6, c7;
	std::vector<ll> l;
	string s;

	std::cin >> n;
	for (c1 = 0; c1 < n; c1++){

		std::cin >> a;
		l.push_back(a);
	}

	std::sort(l.begin(), l.end());
	a = -1;
	b = -1;
	c = -1;
	d = -1;
	ll ans = 0;
	for (c1 = n - 1; c1 > 0; c1--){
		if (a == -1 && l[c1] - l[c1 - 1] <= 1){ a = c1; c1-=2; }
		
		if (c1 > 0 && a != -1){

			if (l[c1] - l[c1 - 1] <= 1){

				ans += l[c1 - 1] * l[a - 1];
				a = -1;
				c1--;
			}


		}



	}

	std::cout << ans<<  "\n";


	return 0;
}