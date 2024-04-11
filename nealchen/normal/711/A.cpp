#include <stdio.h>
int n, i;
char c[1000][6];
int main() {
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%s", c[i]);
		if(c[i][0] == 'O' && c[i][1] == 'O') {c[i][0] = c[i][1] = '+'; break;}
		if(c[i][3] == 'O' && c[i][4] == 'O') {c[i][3] = c[i][4] = '+'; break;}
	}
	if(i == n) {puts("NO"); return 0;} else puts("YES");
	for(++i; i < n; ++i) scanf("%s", c[i]);
	for(i = 0; i < n; ++i) puts(c[i]);
	return 0;
}