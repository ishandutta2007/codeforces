#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,m,z,i,ii,j,r,f[1010],c[1010][1010];
char s[1010];
int main() {
  for (i=2; i<1010; i++) {
    for (ii=i, j=0; ii>0; ii/=2) j+=ii%2;
    f[i]=f[j]+1;
  }
  scanf("%s",s);
  n=strlen(s);
  scanf("%d",&m);
  if (m==0) { puts("1"); return 0; }
  for (i=0; i<=n; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  for (i=z=0; i<n; i++) if (s[i]=='1') {
    if (i>0 && f[z]==m-1) r=(r+1)%md;
    for (j=1; j<=n-1-i; j++) if (f[z+j]==m-1) r=(r+c[n-1-i][j])%md;
    z++;
  }
  if (f[z]==m-1) r=(r+1)%md;
  if (m==1) r=(r+md-1)%md;
  printf("%d\n",r);
  return 0;
}