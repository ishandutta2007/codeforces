#include <stdio.h>

char str[20];

int main() {
	int i,j=0;
	scanf("%s",str);
	for(i=0;str[i];i++)
		if(str[i] == '4' || str[i] == '7')
			j++;
	if(j == 4 || j == 7)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}