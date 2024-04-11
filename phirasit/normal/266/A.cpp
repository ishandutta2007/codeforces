#include <stdio.h>

char str[60];
char stk[60];
int n;

int main() {
	int i,j,ans = 0;
	scanf("%d %s",&n,str);
	for(i=j=0;i<n;i++) {
		if(j > 0 && str[i] == stk[j-1]) {
			ans++;
		}else {
			stk[j++] = str[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}