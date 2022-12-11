#include <stdio.h>
#include <string.h>

#define N 100010

char str[N];

int d2[] = {1, 2, 4, 3};
int d3[] = {1, 3, 4, 2};
int d4[] = {1, 4};

int main() {
	scanf("%s", str);
	int ans = 1;
	
	int l = strlen(str);
	int ls = str[l-1]-'0';
	if(l > 1) {
		ls = 10 * (str[l-2]-'0') + ls;
	}
	ans += d2[ls%4];
	ans += d3[ls%4];
	ans += d4[ls%2];	
	printf("%d\n", ans%5);
	return 0;
}