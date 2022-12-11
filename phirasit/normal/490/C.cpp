#include <stdio.h>
#include <string.h>

#define N 1000010

char str[N];

int dp_lf[N], dp_rg[N];
int a, b;

int main() {
	scanf("%s%d%d", str, &a, &b);
	int val = 0;
	for(int i = 0;str[i];i++) {
		val = (10 * val + str[i] - '0') % a;
		dp_lf[i] = (val == 0);
	}
	val = 0;
	int tmp = 1;
	for(int i = strlen(str) - 1;i >= 0;i--) {
		val = (val + tmp * (str[i] - '0')) % b;
		dp_rg[i] = (val == 0);
		tmp = (10 * tmp) % b;
	}
	int ans = -1;
	for(int i = 0;str[i+1];i++) {
		if(dp_lf[i] && dp_rg[i+1] && str[0] != '0' && str[i+1] != '0') {
			ans = i;
		}
	}
	if(ans == -1) {
		printf("NO\n");
	}else {
		printf("YES\n");
		for(int i = 0;str[i];i++) {
			printf("%c", str[i]);
			if(i == ans) {
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}