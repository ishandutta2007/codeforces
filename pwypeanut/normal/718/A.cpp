#include <bits/stdc++.h>
using namespace std;

int N, T, dp;
char s[200005];
vector<int> v;

int main() {
	scanf("%d%d", &N, &T);
	scanf("%s", &s);
	dp = -1;
	int cur = -1;
	for (int i = 0; i < N; i++) {
		if (s[i] == '.') dp = i;
		if (dp != -1) {
			if (s[i] >= '5') {
				cur = i;
				break;
			}
		}
	}
	if (cur == -1 || T == 0) {
		printf("%s\n", s);
		return 0;
	}
	int bound = cur;
	for (int i = cur; i > dp; i--) {
		if (T == 0) {
			if (s[bound] == '.') bound--;
			for (int j = 0; j <= max(bound, dp - 1); j++) printf("%c", s[j]);
			printf("\n");
			return 0;
		}
		if (s[i] >= '5') {
			// i can round this
			int current = i - 1;
			while (true) {
				if (current == -1) {
					printf("1");
					for (int i = 0; i < dp; i++) printf("0");
					printf("\n");
					return 0;
				}
				else if (s[current] <= '8' && s[current] >= '0') {
					s[current]++;
					T--;
					bound = current;
					break;
				} else if (s[current] == '9') {
					s[current] = '0';
					current--;
				} else current--;
			}
		}
	}
	if (s[bound] == '.') bound--;
	for (int j = 0; j <= max(bound, dp - 1); j++) printf("%c", s[j]);
			printf("\n");
			return 0;
	
}