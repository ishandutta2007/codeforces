#include <stdio.h>
#include <string.h>
int n,i,a,x,y,last,m,r[100100];
char s[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='#') last=i;
  for (i=last+1; i<n; i++) if (s[i]=='(') x--; else x++;
  if (x<0) { puts("-1"); return 0; }
  for (i=0; i<n; i++) if (s[i]==')' || s[i]=='#') {
    if (i==last) y=a-x; else y=1;
    if (y<=0 || y>a) { puts("-1"); return 0; }
    a-=y;
    if (s[i]=='#') r[m++]=y;
  } else a++;
  if (a==0) for (i=0; i<m; i++) printf("%d\n",r[i]); else puts("-1");
  return 0;
}