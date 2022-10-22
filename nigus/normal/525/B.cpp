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
	ll k, z, n, m, x, y, a, b, c,l;
	int c1, c2, c3, c4, c5, c6, c7;
	std::vector<ll> T;
	string s;

	std::cin >> s;
	std::cin >> m;

	l = s.length();
	for (c1 = 0; c1 < l; c1++){

		T.push_back(0);

	}

	for (c1 = 0; c1 < m; c1++){
		std::cin >> a;
		a--;
		T[a]++;

	}
	ll cs = 0;
	string ans = "";
	for (c1 = 0; c1 < l; c1++){

		
		if (c1 < ceil(l / 2)){
			cs += T[c1];

			if (cs % 2 == 0){

				ans += s[c1];
				T[c1] = 0;

			}
			else{

				ans += s[l - c1 -1];

				T[c1] = 1;

			}

		}
		else{

			if (T[l - c1 - 1] == 0){
			
				ans += s[c1];
			
			}
			else{

				ans += s[l - c1 - 1];

			}

		}


	}
	
	std::cout << ans << "\n";


	return 0;
}