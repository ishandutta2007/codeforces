#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		if (n & 1) printf("7"), n -= 3;
		while (n) {
			n -= 2;
			printf("1");
		}
		printf("\n");
	}
	return 0;
}