#include <stdio.h>
#include <string.h>
int n,m,i;
char s[987],t[987];
int main() {
  gets(s); n=strlen(s);
  for (i=n-1; i>=0; i--) if (s[i]==' ') {
    if ((s[i+1]>='0' && s[i+1]<='9') || s[i+1]=='.') t[m++]=' ';
  } else if (s[i]=='.') {
    t[m++]='.'; t[m++]='.'; t[m++]='.'; i-=2;
    t[m++]=' ';  if (i>0 && s[i-1]==' ') i--;
  } else t[m++]=s[i];
  while (m>0 && t[m-1]==' ') m--;
  for (i=m-1; i>=0; i--) {
    if (t[i]!=' ' || (i>0 && t[i-1]=='.') || (i+1<m && t[i+1]==',') ||
      (i>0 && i+1<m && t[i-1]>='0' && t[i-1]<='9' && t[i+1]>='0' && t[i-1]<='9')) putchar(t[i]);
    if (t[i]==',' && i>0 && t[i-1]!=' ') putchar(' ');
  }
  return 0;
}