#include <stdio.h>
#include <string>
int n;
char s[2333], t[2333];
int main() {
	int i, j;
	scanf("%d\n", &n);
	gets(s);
	for(i = 1; i <= n; ++i) {
		for(j = i; j > (i - 1) / 2; --j) {
			t[j] = t[j - 1];
		}
		t[(i - 1) / 2] = s[n - i];
	}
	t[n] = '\0';
	puts(t);
	return 0;
}