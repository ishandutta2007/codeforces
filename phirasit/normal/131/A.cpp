#include <stdio.h>
#include <ctype.h>

char str[110];

int main() {
	int i;
	scanf("%s",str);
	for(i=1;str[i];i++)
		if(!isupper(str[i]))
			break;
	if(str[i]) {
		printf("%s\n",str);
	}else {
		for(i=0;str[i];i++)
			if(islower(str[i]))
				printf("%c",toupper(str[i]));
			else
				printf("%c",tolower(str[i]));
		printf("\n");
	}
	return 0;
}