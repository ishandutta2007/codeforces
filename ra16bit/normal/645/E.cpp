#include <stdio.h>
#include <string.h>
const int md=1000000007;
int n,m,k,i,j,e,last[26],f[2000200];
char s[1000100];
int main() {
  scanf("%d%d",&n,&k);
  scanf("%s",s);
  m=strlen(s);
  f[0]=1;
  for (i=1; i<=m+n; i++) {
    if (i>m) {
      for (e=j=0; j<k; j++) if (last[e]>last[j]) e=j;
    } else e=s[i-1]-'a';
    f[i]=(f[i-1]+f[i-1])%md;
    if (last[e]>0) f[i]=(f[i]+md-f[last[e]-1])%md;
    last[e]=i;
  }
  printf("%d\n",f[m+n]);
  return 0;
}