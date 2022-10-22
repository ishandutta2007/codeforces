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
	ll lim = 600000;
	std::cin >> n >> m;
	std::vector<ll> d;
	std::vector<ll> vis;
	for (c1 = 0; c1 < lim; c1++){
		vis.push_back(0);
		d.push_back(0);
	}

	std::queue<ll> q;

	ll ans = 0;

	q.push(n);

	while (q.size() != 0){

		a = q.front();
		q.pop();
		if (a == m){ break; }

		if (vis[2 * a] == 0 && 4*a < lim && a != 0){
			vis[2 * a] = 1;
			q.push(2 * a);
			d[2*a] = d[a] + 1;

		}

		if (a>=0){

			if (vis[a-1]==0){
				vis[a - 1] == 0;
				q.push(a-1);
				d[a - 1] = d[a] + 1;

			}
			
		}


	}
	std::cout << d[m] << "\n";
	return 0;
}