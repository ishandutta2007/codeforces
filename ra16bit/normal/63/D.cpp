#include <stdio.h>
int a,b,c,d,x,y=1,z,i,j,n,e;
char s[55][105];
int main() {
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
  for (i=1; i<=a; i++) {
    s[0][i]='.';
    for (j=b+1; j<55; j++) s[j][i]='.';
  }
  for (i=1; i<=c; i++) {
    s[0][a+i]='.';
    for (j=d+1; j<55; j++) s[j][a+i]='.';
  }
  if (a&1) { x=b; e=-1; } else { x=1; e=1; }
  for (i=0; i<n; i++) {
    scanf("%d",&z);
    for (j=0; j<z; j++) {
      s[x][y]='a'+i;
      if (s[x+e][y]=='.') { y++; e=-e; } else x=x+e;
    }
  }
  puts("YES");
  for (i=1; i<=b || i<=d; i++) puts(s[i]+1);
  return 0;
}