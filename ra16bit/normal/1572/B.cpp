#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,s,i,le,ri,ans,a[MX],r[MX];
void removelft() {
  while (le+1<=ri) {
    r[ans++]=le-1;
    a[le]=0;
    a[le+1]=0;
    le+=2;
  }
  le=ri=-1;
}
void removergh() {
  while (ri-1>=le) {
    r[ans++]=ri-1;
    a[ri-1]=0;
    a[ri]=0;
    ri-=2;
  }
  le=ri=-1;
}
void upd(int x) {
  while (ri+2<x) {
    r[ans++]=ri;
    a[ri+1]=1;
    a[ri+2]=1;
    ri+=2;
  }
  if (ri+2==x) {
    r[ans++]=ri;
    a[ri]=0;
    a[ri+2]=0;
    --ri;
    removergh();
    i++;
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    s=ans=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    if (s&1) { puts("NO"); continue; }
    le=ri=-1;
    for (i=1; i<=n; i++) if (a[i]==1) {
      if (le!=-1) upd(i);
      if (a[i]==0) continue;
      if (le==-1) le=ri=i;
      for (; ri<=n && a[ri]==1; ri++);
      --ri;
      if ((ri-le)&1) {
        if (le>1 && a[le-1]==0) {
          i=ri;
          removelft();
        } else if (ri<n) {
          i=ri;
          removergh();
        } else {
          puts("NO");
          break;
        }
      } else i=ri;
    }
    if (i<=n) continue;
    printf("YES\n%d\n",ans);
    for (i=0; i<ans; i++) printf("%d ",r[i]);
    if (ans>0) puts("");
  }
  return 0;
}