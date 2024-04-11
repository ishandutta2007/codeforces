#include <stdio.h>
#include <algorithm>
#define MN 100
int n,cnt=0; char s[MN+5];
int main(){
	scanf("%d%s",&n,&s[1]);
	for(int i=1;i<=n;i++) if(s[i]=='8') cnt++;
	printf("%d",std::min(n/11,cnt));
}