#include <stdio.h>
#define MN 105
int n; char str[MN];
int main(){
	scanf("%d%s",&n,&str[1]);
	if(n==1&&str[1]=='0')putchar('0');
	else{
		putchar('1');
		for(int i=1;i<=n;i++)
			if(str[i]=='0')putchar('0');
	}
}