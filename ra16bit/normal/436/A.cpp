#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,i,ii,st,c,cur,r,t[2020],h[2020],a[2020],k[2020],u[2020];
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d%d",&n,&x);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&t[i],&h[i],&a[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (st=0; st<2; st++) {
    cur=x;
    for (c=0; ; c++) {
      for (ii=n-1; ii>=0; ii--) {
        i=k[ii];
        if (u[i]!=st+1 && h[i]<=cur && t[i]==((st+c)&1)) {
          u[i]=st+1;
          cur+=a[i];
          break;
        }
      }
      if (ii<0) break;
    }
    r=max(r,c);
  }
  printf("%d\n",r);
  return 0;
}