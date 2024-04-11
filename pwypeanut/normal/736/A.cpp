#include <bits/stdc++.h>
using namespace std;

long long val[105];

int main() {
	val[0] = val[1] = 1;
	long long N;
	scanf("%lld", &N);
	for (int i = 2; i <= 100; i++) {
		val[i] = val[i - 1] + val[i - 2];
		if (val[i] > N) {
			printf("%d\n", i-2);
			return 0;
		}
	}
	
}