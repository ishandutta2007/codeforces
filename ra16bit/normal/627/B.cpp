#include <bits/stdc++.h>
using namespace std;
int n,m,q,t,x,y,i,A,B,na,nb,a[200200],b[200200];
long long r,tsb,sa[200200],sb[200200];
int main() {
  scanf("%d%d%d%d%d",&n,&m,&B,&A,&q);
  while (q--) {
    scanf("%d%d",&t,&x);
    if (t==1) {
      scanf("%d",&y);
      na=min(A-a[x],y);
      nb=min(B-b[x],y);
      a[x]+=na;
      b[x]+=nb;
      tsb+=nb;
      for (i=x; i<=n; i=(i<<1)-(i&(i-1))) {
        sa[i]+=na;
        sb[i]+=nb;
      }
    } else {
      for (r=tsb, i=x-1; i>0; i&=i-1) r+=sa[i];
      for (i=x+m-1; i>0; i&=i-1) r-=sb[i];
      printf("%I64d\n",r);
    }
  }
  return 0;
}