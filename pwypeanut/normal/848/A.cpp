#include <bits/stdc++.h>
using namespace std;

int K;

int main() {
	scanf("%d", &K);
	if (K == 0) {
		printf("a\n");
		return 0;
	}
	char c = 'a';
	while (K > 0) {
		int cnt = 1;
		for (cnt = 1;; cnt++) {
			if ((long long)cnt * (cnt - 1) / 2 > K) {
				cnt--;
				break;
			}
		}
		K -= (long long)cnt * (cnt - 1) / 2;
		for (int i = 0; i < cnt; i++) printf("%c", c);
		c++;
	}
	printf("\n");
}