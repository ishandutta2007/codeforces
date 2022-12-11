#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

char str[110];
int arr[256];

int main() {
	scanf("%s", str);
	for(int i = 0;str[i];i++) {
		arr[str[i]]++;
	}
	int ans = (arr['n']-1)/2;
	ans = min(ans, arr['i']);
	ans = min(ans, arr['e']/3);
	ans = min(ans, arr['t']);
	printf("%d\n", ans);
	return 0;
}