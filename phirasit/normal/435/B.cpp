#include <stdio.h>

int k;
char str[30];

int main() {
	scanf("%s%d",str,&k);
	for(int i = 0;str[i];i++) {
		int mx = i;
		for(int j = i + 1;str[j] && j-i <= k;j++) {
			if(str[j] > str[mx]) {
				mx = j;
			}
		}
		if(str[mx] > str[i]) {
			char tmp = str[mx];
			for(int j = mx-1;j >= i;j--) {
				str[j+1] = str[j];
			}
			str[i] = tmp;
			k -= mx - i;
		}
	}
	printf("%s\n",str);
}