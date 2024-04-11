#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		if (n == 1) printf("-1\n");
		else {
			for (int j = 0; j < n; j++) {
				if (j == 0) printf("4");
				else printf("3");
			}
			printf("\n");
		}
	}
}