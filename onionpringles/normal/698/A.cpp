#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int c = 0;
	int n; scanf("%d", &n); int L = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int x = a / 2;
		int y = a % 2;
		//printf("%d %d %d %d\n", x, y, a, L);
		if (!x && !y) {
			L = 0;
			c++;
			continue;
		}
		if (x && L == 2) {
			L = 1;
		}
		else if (y && L == 1) {
			L = 2;
		}
		else if (L == 3) {
			if (!y) {
				L = 1;
			}
			else if (!x) L = 2;
			else {
				continue;
			}
		}
		else if (L == 0) {
			if (x&& y) L = 3;
			else if (x) L = 1;
			else if (y) L = 2;
		}
		else {
			L = 0;
			c++;
			continue;
		}
		//printf("%d\n", c);
	}
	printf("%d\n", c);
	//while (1);
}