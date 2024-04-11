#include "bits/stdc++.h"
using namespace std;

long long int n;
long long int m;

long long int k;

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	k++;
	if (k < n) {
		printf("%lld %lld\n", k, 1LL);
		return 0;
	}
	k -= n;
	k--;
	long long int h = k/(m-1LL);
	long long int dc = k%(m-1LL);
	long long int x=n-h;
	long long int y;
	if (h % 2 == 0) {
		y = 2 + dc;
	}
	else {
		y = m - dc;
	}
	printf("%lld %lld\n", x, y);
	return 0;
}