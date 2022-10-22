#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (i) printf(" ");
		printf("%d", mx + x);
		if (x > 0) mx += x;
	}
	printf("\n");
}