#include <stdio.h>
#define MX_N 200010

char str[MX_N];
char ans[MX_N];

int main() {
	int i,j;
	int l = 0;
	scanf("%s",str);
	j = 0;
	for(i=0;str[i];i++) {
		j = ((l > 1 && ans[l-1] == ans[l-2]) || (l > 2 && ans[l-2] == ans[l-3])) + (str[i] == ans[l-1]);
		if(j < 2) {
			ans[l++] = str[i];
		}
	}
	ans[l] = 0;
	printf("%s\n",ans);
	return 0;
}