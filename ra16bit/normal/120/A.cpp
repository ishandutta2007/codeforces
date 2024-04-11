#include <stdio.h>
int n;
char s[8];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%s",s); scanf("%d",&n);
  if ((s[0]=='f' && n==1) || (s[0]=='b' && n==2)) puts("L"); else puts("R");
  return 0;
}