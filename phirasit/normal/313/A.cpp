#include <stdio.h>
#include <string.h>

char str[20];

int main() {
	int i,l;
	scanf("%s",str);
	l = strlen(str);
	if(str[0] != '-')
		printf("%s\n",str);
	else {
		if(l == 2 || (l == 3 && (str[1] == '0' || str[2] == '0'))) {
			printf("0");
		}else {
			if(str[l-1] < str[l-2])
				str[l-2] = ' ';
			else
				str[l-1] = ' ';
			for(i=0;i<l;i++) {
				if(str[i] != ' ')
					printf("%c",str[i]);
			}
			printf("\n");
		}
	}
	return 0;
}