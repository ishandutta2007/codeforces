/* A. Lever */

#include <stdio.h>

#define MX_N 1000010
#define LL long long

char str[MX_N];
LL a,b;

int main() {
	int i,j;
	a = b = 0;
	scanf("%s",str);
	for(i=0;str[i];i++) {
		if(str[i] == '^')
			j = i;
	}
	for(i=0;str[i];i++) {
		if('0' <= str[i] && str[i] <= '9') {
			if(i < j) {
				a += (LL)(j-i) * (str[i] - '0');
			}else {
				b += (LL)(i-j) * (str[i]- '0');
			}
		}
	}
	if(a == b) {
		printf("balance\n");
	}else if(a > b){
		printf("left\n");
	}else {
		printf("right\n");
	}
	return 0;
}