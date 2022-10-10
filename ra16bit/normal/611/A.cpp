#include <stdio.h>
const int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int x,i,r;
char s[7];
int main() {
  scanf("%d",&x);
  scanf("%s",s);
  scanf("%s",s);
  if (s[0]=='w') printf("%d\n",52+int(x==5 || x==6)); else {
    for (i=0; i<12; i++) if (x<=a[i]) r++;
    printf("%d\n",r);
  }
  return 0;
}