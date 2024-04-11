#include <stdio.h>
#include <string.h>
char s[100100];
bool a[12];
int i,n,r,p,t;
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    if (s[i]=='?') t++;
	if (s[i]>='A' && s[i]<='J') a[s[i]-'A']=true;
  }
  r=1; p=10;
  for (i=0; i<12; i++) if (a[i]) r*=p--;
  if (s[0]>='A' && s[0]<='J') { r/=10; r*=9; }
  if (s[0]=='?') { t--; r*=9; }
  printf("%d",r);
  for (i=0; i<t; i++) putchar('0');
  return 0;
}