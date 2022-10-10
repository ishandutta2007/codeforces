#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,tot,l,r,i,n,q,sum[MX];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    for (i=0; i<n; i++) {
      if (i&1) {
        sum[i+1]=(s[i]=='+')?-1:1;
      } else {
        sum[i+1]=(s[i]=='+')?1:-1;
      }
      sum[i+1]+=sum[i];
    }
    while (q--) {
      scanf("%d%d",&l,&r);
      tot=sum[r]-sum[l-1];
      if (tot==0) puts("0"); else if ((r-l)&1) puts("2"); else puts("1");
    }
  }
  return 0;
}