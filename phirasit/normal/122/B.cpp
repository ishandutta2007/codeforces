#include <stdio.h>

#define MX_N 60

char str[MX_N];
int a,b;

int main() {
	int i;
	a = b = 0;
	scanf("%s",str);
	for(i=0;str[i];i++) {
		a += (str[i] == '4');
		b += (str[i] == '7');
	}
	if(!a && !b) {
		printf("-1\n");
	}else if(a >= b) {
		printf("4\n");
	}else {
		printf("7\n");
	}
	return 0;
}