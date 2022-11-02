#include <stdio.h>
#include <string.h>
char s[100086], t[38];
int ans = 0, i, j, sl, tl;
int main() {
	scanf("%s%s", s, t);
	for(sl = 0; s[sl]; ++sl);
	for(tl = 0; t[tl]; ++tl);
	for(i = 0; i + tl <= sl; ) {
		for(j = 0; j < tl; ++j) if(s[i + j] != t[j]) goto orz;
		++ans;
		i += tl;
		continue;
		orz: ++i;
	}
	printf("%d", ans);
	return 0;
}