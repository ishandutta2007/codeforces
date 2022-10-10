#include <stdio.h>
#include <string.h>
int n,i,j,x,z,cur,last,a[111];
char s[111];
int main() {
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) {
    for (j=0; j<8; j++, last>>=1) a[j]=last&1;
    for (j=cur=0; j<8; j++) cur=cur*2+a[j];
    z=s[i];
    for (j=0; j<8; j++, z>>=1) a[j]=z&1;
    for (j=x=0; j<8; j++) x=x*2+a[j];
    printf("%d\n",(cur-x+256)&255);
    
    last=s[i];
  }
  return 0;
}