#include <stdio.h>

char str[60];
int n,k;

int main() {
	int i;
	scanf("%d %d %s",&n,&k,str);
	while(k--) {
		for(i=n-1;i>0;i--) {
			if(str[i] == 'G' && str[i-1] == 'B') {
				str[i] = 'B';
				str[i-1] = 'G';
				i--;
			}
		}
	}
	printf("%s\n",str);
	return 0;
}