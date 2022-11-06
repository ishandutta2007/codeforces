#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (n % i == 0) {
			printf("%d%d", i, n / i);
			return 0;
		}
	assert(0);
}