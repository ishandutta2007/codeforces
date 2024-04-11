#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,ii,i,j,x,y,a[MX],k[MX],cnt[MX];
long long s;
bool cmp(int i, int j) { return a[i]>a[j]; }
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (s=0, i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      cnt[i]=0;
      k[i-1]=i;
      s+=a[i];
    }
    for (i=1; i<n; i++) {
      scanf("%d%d",&x,&y);
      ++cnt[x];
      ++cnt[y];
    }
    sort(k,k+n,cmp);
    printf("%lld",s);
    for (ii=0; ii<n; ii++) {
      i=k[ii];
      for (j=1; j<cnt[i]; j++) {
        s+=a[i];
        printf(" %lld",s);
      }
    }
    puts("");
  }
  return 0;
}