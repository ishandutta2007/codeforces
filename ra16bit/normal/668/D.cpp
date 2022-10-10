#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=1000100;
int n,i,j,z,r,a[MX],t[MX],x[MX],k[MX],o[MX],p[MX],s[MX];
bool cmp(int i, int j) {
  if (x[i]!=x[j]) return x[i]<x[j];
  return t[i]<t[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&a[i],&t[i],&x[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (i=1; i<n; i++) {
    if (x[k[i]]==x[k[i-1]]) p[i]=p[i-1]; else p[i]=i;
    o[k[i]]=i;
  }
  for (i=0; i<n; i++) {
    z=o[i]+1;
    if (a[i]==3) {
      for (r=0, j=z; j>0; j&=j-1) r+=s[j];
      for (j=p[z-1]; j>0; j&=j-1) r-=s[j];
      printf("%d\n",r);
    } else {
      r=(a[i]==1)?1:-1;
      for (j=z; j<=n; j=(j<<1)-(j&(j-1))) s[j]+=r;
    }
  }
  return 0;
}