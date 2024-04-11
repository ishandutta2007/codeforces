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
	ll k, z, n, m, x, y, a, b, c;
	int c1, c2, c3, c4, c5, c6, c7;



	std::cin >> n >> k;

	std::vector<std::vector<int> > C(k, std::vector<int>());
	std::vector<int> l;
	std::vector<int> ked;
	std::vector<int> ind;
	std::vector<int> free;

	for (c1 = 0; c1 < n; c1++){


		ked.push_back(0);
		ind.push_back(0);
		free.push_back(0);

	}



	for (c1 = 0; c1 < k; c1++){
		std::cin >> a;
		l.push_back(a);

		for (c2 = 0; c2 < a; c2++){

			std::cin >> b;
			b--;
			C[c1].push_back(b);
			ked[b] = c1;
			ind[b] = c2;
			if (a == 1){ free[b] = 1; }


		}



	}



	int nu = 0;
	ll ans = 0;

	while (nu < n - 1){
		//cout << ans << " ";

		if (ked[nu] == ked[nu + 1] && ind[nu] + 1 == ind[nu + 1]){}
		else{


			if (free[nu] == 0){
				for (c1 = ind[nu] + 1; c1 < l[ked[nu]]; c1++){

					x = C[ked[nu]][c1];
					free[x] = 1;
					ind[x] = -1;
					ans++;

				}
				
			}
			if (free[nu + 1] == 1){

				ans++;



			}
			else{

				for (c1 = ind[nu + 1]; c1 < l[ked[nu + 1]]; c1++){

					x = C[ked[nu + 1]][c1];
					free[x] = 1;
					ind[x] = -1;
					ans++;

					//cout << nu + 1 << " "<<x<<" "<<l[ked[nu+1]]<<" ";

				}



			}


		}
		

		nu++;


	}

	std::cout << ans << "\n";


	return 0;
}