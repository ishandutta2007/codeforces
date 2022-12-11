#include <stdio.h>
#include <string.h>

char str[20];
int opt[20];

int main() {
	int i,l;
	scanf("%s",str);
	l = strlen(str);
	opt[l] = 1;
	for(i=l-1;i>=0;i--) {
		opt[i] = 0;
		if(str[i] == '1' && opt[i+1])
			opt[i] = 1;
		if(str[i] == '1' && str[i+1] == '4' && opt[i+2])
			opt[i] = 1;
		if(str[i] == '1' && str[i+1] == '4' && str[i+2] == '4' && opt[i+3])
			opt[i] = 1;
	}
	if(opt[0])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}