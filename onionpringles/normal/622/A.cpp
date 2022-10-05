#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long sum = 0;
	int cur = 1;
	while (1) {
		sum = sum + cur;
		if (sum >= n) {
			sum = sum - cur;
			break;
		}
		cur++;
	}
	printf("%I64d", n - sum);
}