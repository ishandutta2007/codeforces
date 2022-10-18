#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;



int main()
{
	int n;
	cin >> n;
	if (n < 3)
	{
		if (n == 1) cout << "0 1";
		else cout << "0 2";
			return 0;
	}
	int t = 0, q = 0;
	if (n % 7 == 6) t = 1;
	if (n % 7 == 1) q = 1;
	cout << (n / 7) * 2 + t << " " << 2 + ((n - 2) / 7) * 2 + q;

	return 0;
}