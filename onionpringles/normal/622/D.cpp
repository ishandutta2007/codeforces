#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int a[1000000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n / 2; i++) {
		a[n-1-i] = a[i] = 2 * i + 1;
	}
	if (n % 2) {
		a[n / 2] = n;
	}
	else {
		a[n + n / 2] = n;
	}
	a[n] = n;
	for (int i = 0; i < (n - 1) / 2; i++) {
		a[n + 1 + i] = a[2*n - 1 - i] = 2 * i + 2;
	}
	for (int i = 0; i < 2 * n; i++) printf("%d ", a[i]);
}