#include <stdio.h>
#include <stdlib.h>

int n;
char str[10];

int main() {
	int x = 0;
	scanf("%d",&n);
	while(n--) {
		scanf("%s",str);
		if(str[1] == '-')
			x--;
		else
			x++;
	}
	printf("%d\n",x);
	return 0;
}