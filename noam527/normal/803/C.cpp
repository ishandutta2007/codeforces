#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, gcd = 1, maxgcd, stopat;

int main()
{
	cin >> n >> k;
	if (k > 1000000 || k * (k + 1) / 2 > n)
	{
		cout << -1;
		return 0;
	}
	maxgcd = n / (k * (k + 1) / 2), stopat = (sqrt(n) < maxgcd) ? sqrt(n) : maxgcd;
	for (int i = 1; i <= stopat; i++)
		if (n % i == 0)
		{
			if (n / i <= maxgcd)
			{
				gcd = n / i;
				break;
			}
			gcd = i;
		}
	for (int i = 1; i < k; i++)
		cout << gcd * i << " ";
	cout << n - (k * (k - 1) / 2 * gcd) << endl;
	return 0;
}