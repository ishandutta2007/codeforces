#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		if (n == 1) {
			printf("-1\n");
			continue;
		}
		printf("2"), n--;
		while (n--) printf("3");
		printf("\n");
	}
	return 0;
}