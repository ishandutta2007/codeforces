#include <stdio.h>

char a[110],b[110];

int main() {
	int i;
	scanf("%s %s",a,b);
	for(i=0;a[i];i++)
		printf("%d",a[i] != b[i]);
	return 0;
}