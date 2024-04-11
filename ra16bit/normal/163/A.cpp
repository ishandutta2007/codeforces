#include <stdio.h>
#include <string.h>
int i,j,x,r,n,m,f[5005][5005],md=1000000007;
char s[5005],t[5005];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=n-1; i>=0; i--) for (j=m-1; j>=0; j--) {
    f[i][j]=f[i][j+1];
    if (s[i]==t[j]) {
      x=f[i+1][j+1]+1;
      if (x>=md) x-=md;
      r+=x;
      if (r>=md) r-=md;
      f[i][j]+=x;
      if (f[i][j]>=md) f[i][j]-=md;
    }
  }
  printf("%d\n",r);
  return 0;
}