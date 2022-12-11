#include <stdio.h>

char tmp1[] = "lala.";
char tmp2[] = "miao.";
char str[110];

int main() {
	int i,l,t;
	int a,b;
	char tmp;
	scanf("%d%c",&t,&tmp);
	while(t--) {
		i = 0;
		while(1) {
			scanf("%c",&str[i]);
			if(str[i++] == '\n') break;
		}
		l = i-2;
		a = b = 0;
		for(i=0;i<5 && str[i] != '\n';i++)
			if(str[i] != tmp2[i])
				break;
		if(i >= 5) a = 1;
		for(i=l-4;i>=0 && i<=l;i++)
			if(str[i] != tmp1[i-l+4])
				break;
		if(i > l) b = 1;
		if(a && b) {
			printf("OMG>.< I don't know!\n");
		}else if(b) {
			printf("Freda's\n");
		}else if(a) {
			printf("Rainbow's\n");
		}else {
			printf("OMG>.< I don't know!\n");
		}
	}
	return 0;
}