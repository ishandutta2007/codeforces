#include <bits/stdc++.h>
using namespace std;
char s[123123];
int main() {
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 3; i <= l; ++i)
		if (((s[i - 2] - 'A') + (s[i - 1] - 'A')) % 26 != s[i] - 'A') {
			puts("NO"); return 0;
		}
	puts("YES");
}