#include <stdio.h>
#include <string.h>
const int md=1000000007;
int n,m,i,k,last,p[200200],f[200200],a[200200],b[200200];
char s[200200],t[200200];
int main() {
  scanf("%s",t); m=strlen(t);
  scanf("%s",s); n=strlen(s);
  s[n]='$';
  for (i=0; i<m; i++) s[n+i+1]=t[i];
  m=n+m+1;
  f[n]=a[n]=b[n]=1;
  for (i=1; i<m; i++) {
    while (k>0 && s[k]!=s[i]) k=p[k-1];
    if (s[k]==s[i]) k++;
    p[i]=k;
    if (p[i]==n) last=i-n;
    if (last>=n) f[i]=b[last];
    a[i]=(a[i-1]+f[i])%md;
    b[i]=(b[i-1]+a[i])%md;
  }
  printf("%d\n",(a[m-1]+md-1)%md);
  return 0;
}