#pragma warning(disable:4996)
#include <stdio.h>
char buf[1000][10];
int main() {
	int n; scanf("%d", &n);
	bool good = false;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < n; i++) {
		if (buf[i][0] == buf[i][1] && buf[i][1] == 'O') {
			good = true;
			buf[i][0] = buf[i][1] = '+'; break;
		}
		else if (buf[i][3] == buf[i][4] && buf[i][4] == 'O') {
			good = true;
			buf[i][3] = buf[i][4] = '+'; break;
		}
	}
	if (good) puts("YES"); else puts("NO");
	if (good) {
		for (int i = 0; i < n; i++) {
			printf("%s\n", buf[i]);
		}
	}
}