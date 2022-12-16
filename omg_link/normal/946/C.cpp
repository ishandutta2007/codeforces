#include <stdio.h>
#include <string.h>
#define MN 100005
char str[MN],now='a';
int main(){
	scanf("%s",str+1); int len=strlen(str+1);
	for(int i=1;i<=len;i++)
		if(str[i]<=now){
			str[i]=now,now++;
			if(now=='z'+1)break;
		}
	if(now=='z'+1){printf("%s",str+1);}
	else printf("-1");
}