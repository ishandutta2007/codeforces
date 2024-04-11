
#include <stdio.h>

int n;
char str[110];

int main() {
	scanf("%d%s", &n, str);
	int i;
	for(i = 0;str[i+1] && str[i] == '1';i++);
	printf("%d\n", i+1);
	return 0;
}