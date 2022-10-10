#include <stdio.h>
int a1,b1,a2,b2,i,j,x,y,r;
char s[5];
int abs(int x) { return (x<0)?-x:x; }
int main() {
  gets(s); a1=s[0]-'a'; a2=s[1]-'1';
  gets(s); b1=s[0]-'a'; b2=s[1]-'1';
  for (i=0; i<8; i++) if (i!=a1) for (j=0; j<8; j++) if (j!=a2 && (i!=b1 || j!=b2)) {
    x=abs(a1-i); y=abs(a2-j);
    if (x==1 && y==2) continue;
    if (x==2 && y==1) continue;
    x=abs(b1-i); y=abs(b2-j);
    if (x==1 && y==2) continue;
    if (x==2 && y==1) continue;
    r++;
  }
  printf("%d\n",r);
  return 0;
}