#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long n;
char s[30], t;
int ord[] = {4, 5, 6, 3, 2, 1};
int main() {
	scanf("%[0-9]%c", s, &t);
	n = atoll(s);
	return !printf("%lld", (n - 1) / 4 * 16 + (n - 1) % 2 * 7 + ord[t - 'a']);
}