#include <stdio.h>

char str[10010];
int l;

int punc(char ch) {
	return ch == '.' || ch == ',' || ch == '!' || ch == '?';
}
int main() {
	int i,j;
	l = 0;
	while(1) {
		scanf("%c",&str[l]);
		if(str[l++] == '\n') break;
	}
	l--;
	for(i=0;i<l;i++) {
		if(punc(str[i])) {
			printf("%c ",str[i]);
			j = 1;
		}else if(str[i] == ' ') {
			if(str[i+1] != ' ' && !punc(str[i+1]) && !j)
				printf(" ");
		}else {
			j = 0;
			printf("%c",str[i]);
		}
	}
	return 0;
}