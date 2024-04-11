#include <bits/stdc++.h>

int T;
char str[1000];
char key[1000];
int occur[26];

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf(" %s", str);
		int l = strlen(str);
		for (int i = 0; i < 26; ++i) occur[i] = 0;
		int cur = 500, low = 500, high = 500;
		key[cur] = str[0];
		occur[str[0] - 'a'] = 1;
		for (int i = 1; i < l; ++i) {
			if (occur[str[i] - 'a'] == 1) {
				if (low < cur && key[cur - 1] == str[i]) {
					--cur;
				} else if (high > cur && key[cur + 1] == str[i]) {
					++cur;
				} else {
					printf("NO\n");
					goto end;
				}
			} else {
				occur[str[i] - 'a'] = 1;
				if (high == cur) {
					++high; key[++cur] = str[i];
				} else if (low == cur) {
					--low; key[--cur] = str[i];
				} else {
					printf("NO\n");
					goto end;
				}
			}
		}
		for (int i = 0; i < 26; ++i) if (!occur[i]) {
			key[++high] = i + 'a';
		}
		printf("YES\n");
		for (int i = low; i <= high; ++i) printf("%c", key[i]);
		printf("\n");
		end:;
	}
}