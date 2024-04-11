#include <bits/stdc++.h>
using namespace std;
int t,n,i,le,ri,x,ans,r[400400];
char a[100100],b[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    for (i=0; i<n; i++) {
      a[i]-='0';
      b[i]-='0';
    }
    le=x=ans=0; ri=n-1;
    for (i=n-1; i>=0; i--) {
      if ((a[ri]^x)!=b[i]) {
        if ((a[le]^x)==b[i]) r[ans++]=1;
        r[ans++]=i+1;
        swap(le,ri);
        x^=1;
      }
      if (le>ri) ++ri; else --ri;
    }
    printf("%d",ans);
    for (i=0; i<ans; i++) printf(" %d",r[i]);
    puts("");
  }
  return 0;
}