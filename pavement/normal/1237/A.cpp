#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	bool c = false;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i : a) {
		if (i % 2 == 0) printf("%d\n", i / 2);
		else if (c) printf("%d\n", (int)ceil(double(i) / 2.)), c = false;
		else printf("%d\n", (int)floor(double(i) / 2.)), c = true;
	}
}