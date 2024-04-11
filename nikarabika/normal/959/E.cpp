//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)

const int maxn = 1e5 + 10;

LL calc(LL n) {
	if (n == 1)
		return 0;
	if (n % 2 == 0)
		return n / 2 + calc(n / 2) * 2;
	n--;
	return (n & -n) + calc(n);
}

int main() {
	LL n;
	cin >> n;
	cout << calc(n) << endl;
	return 0;
}