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
	ll k, n, m, b,x,y;
	int c1, c2, c3, c4, c5, c6;
	string s;
	std::vector<ll> a;
	std::vector<ll> d;

	std::cin >> n;
	for (c1 = 0; c1 < n; c1++){

		std::cin >> b;
		a.push_back(b);
		d.push_back(b + c1);


	}

	std::sort(d.begin(), d.end());

	
	for (c1 = 0; c1 < n; c1++){
		d[c1] -= c1;

	}
	bool fail = 0;
	for (c1 = 0; c1 < n-1; c1++){
		if (d[c1]>d[c1 + 1]){ fail = 1; }

	}

	if (fail == 1){ std:cout << ":(\n"; }
	else{

		for (c1 = 0; c1 < n-1; c1++){
			std::cout << d[c1] << " ";

		}
		std::cout << d[n-1] << "\n";

	}
	

	return 0;
}