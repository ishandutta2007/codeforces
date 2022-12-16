#include <bits/stdc++.h>

int T;
char str[1000];

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf(" %s", str);
		int l = strlen(str);
		int ans = 0;
		for (int i = 0; i < l; ++i)
			if (str[i] == '0') ++ans;
		for (int i = 0; i < l && str[i] == '0'; ++i) --ans;
		for (int i = l - 1; i >= 0 && str[i] == '0'; --i) --ans;
		printf("%d\n", std::max(0, ans));
	}
}