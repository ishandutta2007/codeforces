#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>

using namespace std;

int x[202020];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	sort(x, x + n);
	int minval = 2000000000;
	for (int i = 0; i +n/2<n; i++) {
		if (x[i + n / 2] - x[i] < minval) minval = x[i + n / 2] - x[i];
	}
	printf("%d", minval);
}