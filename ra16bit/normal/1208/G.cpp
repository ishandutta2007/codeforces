#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int n,m,i,j,k,a[MX],b[MX],c[44],cnt[44],d[44];
long long r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=2; i<=n; i++) {
    b[i]=i-1;
    if (a[i]) {
      for (k=0, j=i; j>1; j/=a[j]) {
        if (k==0 || c[k-1]!=a[j]) {
          c[k++]=a[j];
          cnt[k-1]=1;
          d[k-1]=a[j];
        } else {
          cnt[k-1]++;
          d[k-1]*=a[j];
        }
      }
      for (b[i]=1, j=0; j<k; j++) b[i]*=d[j]-d[j]/c[j];
    } else for (j=i; j<=n; j+=i) a[j]=i;
    if (i==2) b[i]=0;
  }
  sort(b+3,b+n+1);
  for (r=1, i=0; i<m; i++) r+=b[i+3];
  printf("%I64d\n",r+int(m>1));
  return 0;
}