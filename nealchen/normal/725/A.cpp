#include <stdio.h>
int n, ans = 0, i;
char s[200001];
int main() {
	scanf("%d%s", &n, s);
	for(i = 0; i < n && s[i] == '<'; ++i) ++ans;
	for(i = n - 1; i >= 0 && s[i] == '>'; --i) ++ans;
	return !printf("%d", ans);
}