#include <stdio.h>
#include <string.h>
int c,i,j,m,r=1;
long long b,t[10];
char s[1100000],n[1100000];
int main() {
  scanf("%s %s %d",&s,&n,&c);
  m=strlen(s);
  for (i=0; i<m; i++) b=(b*10+s[i]-'0')%c;
  t[0]=1LL%c;
  for (i=1; i<10; i++) t[i]=(t[i-1]*b)%c;
  m=strlen(n);
  for (i=m-1; i>=0; i--) {
    n[i]--;
    if (n[i]>='0') break; else n[i]='9';
  }
  for (i=0; i<m; i++) {
    long long ro=r;
    for (j=1; j<10; j++) r=(r*ro)%c;
    r=(r*t[n[i]-'0'])%c;
  }
  r=(r*(b+c-1))%c;
  if (r==0) printf("%d\n",c); else printf("%d\n",r);
  return 0;
}