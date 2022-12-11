#include <stdio.h>

char str[300];

int main() {
	int i,j;
	scanf("%s",str);
	j = 1;
	for(i=0;str[i];)
		if(str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B') {
			if(j == 0) printf(" ");
			j = 1;
			i += 3;
		}else {
			printf("%c",str[i++]);
			j = 0;
		}
	printf("\n");
	return 0;
}