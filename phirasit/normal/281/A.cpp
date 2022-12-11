#include <stdio.h>
#include <ctype.h>

char str[1000];

int main() {
	int i;
	scanf("%s",str);
	printf("%c",toupper(str[0]));
	for(i=1;str[i];i++)
		printf("%c",str[i]);
	printf("\n");
	return 0;
}