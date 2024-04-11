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
	ll k, n, m, a, b,x,y;
	int c1, c2, c3, c4, c5, c6;
	string s;
	std::vector<ll> man;

	std::cin >> n >> m;

	std::vector<std::vector<ll> > A(n, std::vector<ll>());
	std::vector<std::vector<ll> > B(n, std::vector<ll>());
	for (c1 = 0; c1 < n; c1++){

		std::cin >> s;
		for (c2 = 0; c2 < m; c2++){
			if (s[c2] == 'W'){ a = 1; }
			else{ a = -1; }
			A[c1].push_back(a);
			B[c1].push_back(0);

		}

	}

	for (c1 = 0; c1 < n; c1++){
		for (c2 = 0; c2 < m; c2++){
			man.push_back(-((c1 + c2) * 100000 + c1));
			
		}
	}
	std::sort(man.begin(), man.end());
	ll l = man.size();
	int ans = 0;
	for (c1 = 0; c1 < l; c1++){
		a = -man[c1];
		x = a % 100000;
		y = round((a - x) / 100000) - x;
		if (B[x][y] != A[x][y]){
			b = A[x][y] - B[x][y];
			ans += 1;
			for (c2 = 0; c2 <= x; c2++){
				for (c3 = 0; c3 <= y; c3++){
					B[c2][c3] += b;
					//cout << B[c2][c3] << " ";
				}
			}
		}
		


	}
	std::cout << ans << "\n";

	return 0;
}