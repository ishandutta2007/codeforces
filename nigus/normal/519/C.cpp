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
	std::cin >> n >> m;
	ll ans = 0;
	while (n + m >= 3 && n > 0 && m > 0){

		if (m > n){ m -= 2; n--; ans++; }
		else{ n -= 2; m--; ans++; }

	}
	std::cout << ans << "\n";

	return 0;
}