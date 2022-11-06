#include <bits/stdc++.h>
using namespace std;
char s[123];
int n;

bool chk(char c) {
	return c == 'A' || c == 'E' || c == 'F' || c == 'H' || c == 'I' || c == 'K' || c == 'L' || c == 'M' || c == 'N'||
		   c == 'T' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z';
}

int main() {
	scanf("%s", s); n = strlen(s);
	for (int i = 1; i < n; ++i)
		if (chk(s[i]) != chk(s[0])) {
			puts("NO"); return 0;
		}
	puts("YES");
}