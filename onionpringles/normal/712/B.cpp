#include <stdio.h>
#include <string.h>
char buf[100001];
int main(){scanf("%s",buf);int n=strlen(buf);if(n&1){puts("-1");return 0;}int x=0,y=0;for(int i=0;i<n;i++){if(buf[i]=='L')x--;else if(buf[i]=='R')x++;else if(buf[i]=='U')y++;else if(buf[i]=='D') y--;}if(x<0)x=-x;if(y<0)y=-y;printf("%d\n",(x+y)/2);}