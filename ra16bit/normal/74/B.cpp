#include <stdio.h>
#include <string.h>
int n,x,y,m,d,i;
char s[222];
int main() {
  scanf("%d%d%d",&n,&x,&y);
  scanf("%s",s); scanf("%s",s);
  if (s[0]=='t') d=1; else d=-1;
  scanf("%s",s); m=strlen(s);
  for (i=0; i<m-1; i++) if (s[i]=='0') {
    if (d==-1) {
      if (x>1) x--;
      if (--y==1) d=-d;
    } else {
      if (x<n) x++;
      if (++y==n) d=-d;
    }
    if (x==y) { printf("Controller %d",i+1); return 0; }
  } else {
    if (d==-1) {
      x=n;
      if (--y==1) d=-d;
    } else {
      x=1;
      if (++y==n) d=-d;
    }    
  }
  puts("Stowaway");
  return 0;
}