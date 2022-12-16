#include <stdio.h>
#define MN 100
int n,c=0,a=0;
char s[MN+5];
int main(){
	scanf("%d%s",&n,&s[1]);
	for(int i=1;i<=n;i++)
		if(s[i]=='x'){
			c++;
			if(c>2)a++;
		}else c=0;
	printf("%d",a);
}