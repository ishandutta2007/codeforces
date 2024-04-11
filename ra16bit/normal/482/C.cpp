#include <stdio.h>
#include <string.h>
int n,m,i,j,k,mask,b[1100100];
double c,r,f[1100100];
long long a[1100100];
char s[55][55];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  m=strlen(s[0]);
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
    for (mask=k=0; k<m; k++) if (s[i][k]==s[j][k]) mask|=(1<<k);
    a[mask]|=(1LL<<i);
    a[mask]|=(1LL<<j);
  }
  for (i=(1<<m)-1; i>=0; i--) for (j=0; j<m; j++) if (i&(1<<j)) a[i^(1<<j)]|=a[i];
  f[0]=1;
  for (i=0; i<(1<<m); i++) {
    b[i]=b[i/2]+(i&1);
    for (j=0; j<m; j++) if (((i>>j)&1)==0) f[i^(1<<j)]+=f[i]/double(m-b[i]);
    for (c=j=0; j<n; j++) if (a[i]&(1LL<<j)) c++;
    r+=f[i]*c/n;
  }
  printf("%.12lf\n",r);
  return 0;
}