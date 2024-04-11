#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,e,x,MSK,mask,prv,mx[2020],k[2020],a[14][2020],b[(1<<12)+5],best[(1<<12)+5],f[14][(1<<12)+5];
bool cmp(int i, int j) { return mx[i]>mx[j]; }
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (j=0; j<m; j++) { mx[j]=0; k[j]=j; }
    for (i=0; i<n; i++) for (j=0; j<m; j++) {
      scanf("%d",&a[i][j]);
      mx[j]=max(mx[j],a[i][j]);
    }
    sort(k,k+m,cmp);
    MSK=(1<<n);
    for (i=0; i<min(m,n); i++) {
      x=k[i];
      for (mask=0; mask<MSK; mask++) best[mask]=0;
      for (j=0; j<n; j++) {
        for (b[0]=0, mask=1; mask<MSK; mask++) {
          for (e=0; e<n; e++) if ((mask>>e)&1) {
            b[mask]=b[mask^(1<<e)]+a[(j+e)%n][x];
            break;
          }
          best[mask]=max(best[mask],b[mask]);
        }
      }
      if (i==0) {
        for (mask=0; mask<MSK; mask++) f[0][mask]=best[mask];
      } else for (mask=0; mask<MSK; mask++) {
        f[i][mask]=0;
        for (prv=mask; ; prv=((prv-1)&mask)) {
          f[i][mask]=max(f[i][mask],f[i-1][prv]+best[mask^prv]);
          if (prv==0) break;
        }
      }
    }
    printf("%d\n",f[min(m,n)-1][MSK-1]);
  }
  return 0;
}