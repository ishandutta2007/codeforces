#pragma warning(disable:4996)
#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int mod = 1000000007;

int pow(int n, int a) {
	if (a == 0) return 1;
	int tmp = pow(n, a / 2);
	tmp = (LL)tmp*tmp%mod;
	if (a % 2 == 1) {
		tmp = (LL)tmp*n%mod;
	}
	return tmp;
}


int main() {
	int p, k;
	scanf("%d %d", &p, &k);
	int tmp = 1; int res;
	if (k) {
		int i;
		for (i = 1; i < p; i++) {
			tmp = (LL)tmp*k%p;
			if (tmp%p == 1) break;
		}
		if (i == 1) {
			res = pow(p, p);
		}
		else {
			int orbit = (p - 1) / i;
			res = pow(p, orbit);
		}
	}
	else {
		res = pow(p, p - 1);
	}
	printf("%d", res);
	return 0;
}