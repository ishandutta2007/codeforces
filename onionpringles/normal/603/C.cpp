#pragma warning(disable:4996)

#include <stdio.h>

int seq[100000];

int gn(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 0;
	else if (n == 3) return 1;
	else if (n == 4) return 2;
	else if (n % 2) return 0;
	else {
		int m = gn(n / 2);
		if (m == 1) return 2;
		else return 1;
	}
}
int gn2(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	else {
		if (n % 2) return 0;
		else return 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", seq + i);
	int state = 0;
	if (k % 2) {
		for (int i = 0; i < n; i++) state ^= (gn(seq[i]));
	}
	else {
		for (int i = 0; i < n; i++) state ^= (gn2(seq[i]));
	}
	if (state == 0) puts("Nicky");
	else puts("Kevin");
}