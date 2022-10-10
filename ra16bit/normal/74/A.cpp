#include <stdio.h>
int i,j,k,x,y,n,r[55];
char s[55][55];
int main() {
  scanf("%d",&n);
  for (i=k=0; i<n; i++) {
    scanf("%s",s[i]);
    scanf("%d%d",&x,&y);
    r[i]=x*100-y*50;
    for (j=0; j<5; j++) { scanf("%d",&x); r[i]+=x; }
    if (r[i]>r[k]) k=i;
  }
  printf("%s\n",s[k]);
  return 0;
}