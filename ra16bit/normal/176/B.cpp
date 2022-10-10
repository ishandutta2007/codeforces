#include <stdio.h>
#include <string.h>
int n,m,i,j,k,f[1010],sum,res,md=1000000007;
char s[1010],t[1010];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); scanf("%d",&m);
  f[0]=1; sum=1;
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      f[j]=sum-f[j];
      if (f[j]<0) f[j]+=md;
    }
    sum=((n-1LL)*sum)%md;
  }
  for (i=0; i<n; i++) {
    for (j=0, k=i; j<n; j++, k++) {
      if (k==n) k=0;
      if (s[j]!=t[k]) break;
    }
    if (j>=n) {
      res+=f[i];
      if (res>=md) res-=md;
    }
  }
  printf("%d\n",res);
  return 0;
}