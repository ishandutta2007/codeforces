#include <cstdio>
#include <algorithm>
using namespace std;
const int md=1000000007;
int n,m,i,j,k,e,r,c[2020],o[2020],f[2020][2020];
char s[2020];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (i=0; i<n; i++) c[i]=s[i]-'a';
  f[0][0]=1;
  for (i=0; i<=n; i++) for (j=0; j<=m; j++) {
    o[j]=(o[j]+f[i][j])%md;
    if (i<n && s[i]>'a') f[i+1][j]=(f[i+1][j]+((long long)c[i])*o[j])%md;
    if (i<n && s[i]<'z') {
      long long z=25-c[i];
      for (k=i, e=n-i; k>=0 && j+e<=m; k--, e+=n-i) f[i+1][j+e]=(f[i+1][j+e]+z*f[k][j])%md;
    }
  }
  printf("%d\n",o[m]);
  return 0;
}