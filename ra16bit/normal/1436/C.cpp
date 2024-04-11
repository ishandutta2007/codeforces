#include <bits/stdc++.h>
using namespace std;
const int MX=1010,md=1000000007;
int n,x,i,j,pos,l,r,h,ls,gr;
long long f[MX],c[MX][MX],res;
int main() {
  scanf("%d%d%d",&n,&x,&pos);
  c[0][0]=1;
  for (f[0]=i=1; i<=n; i++) {
    f[i]=(f[i-1]*i)%md;
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  l=0; r=n;
  while (l<r) {
    h=(l+r)/2;
    if (pos>=h) {
      if (h!=pos) ls++;
      l=h+1;
    } else {
      gr++;
      r=h;
    }
  }
  if (gr>n-x || ls>x-1 || n-1-ls-gr<0) { puts("0"); return 0; }
  res=(c[n-x][gr]*f[gr]%md)%md;
  res=(res*(c[x-1][ls]*f[ls]%md))%md;
  res=(res*f[n-1-ls-gr])%md;
  printf("%d\n",int(res));
  return 0;
}