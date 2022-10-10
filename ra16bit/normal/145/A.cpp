#include <stdio.h>
#include <string.h>
int n,x,y,z,r,c,i;
char a[100100],b[100100];
int main() {
  gets(a); n=strlen(a); gets(b);
  for (i=0; i<n; i++) {
    if (a[i]=='4') x++;
    if (b[i]=='4') y++;
  }
  if (x>y) {
    z=x-y;
    for (i=0; i<n && z>0; i++) if (a[i]=='4' && b[i]=='7') { a[i]='7'; r++; z--; }
  } else {
    z=y-x;
    for (i=0; i<n && z>0; i++) if (b[i]=='4' && a[i]=='7') { b[i]='7'; r++; z--; }
  }
  for (i=0; i<n; i++) if (a[i]!=b[i]) c++;
  printf("%d\n",r+c/2);
  return 0;
}