#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,lst,poslst,posprv,a[2222],ans[20200];
bool ok;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    ok=true;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      if ((a[i]&1)!=(i&1)) ok=false;
    }
    if (!ok) { puts("-1"); continue; }
    m=0;
    for (lst=n; lst>=3; lst-=2) {
      for (i=1; i<=lst; i++) if (a[i]==lst) poslst=i; else if (a[i]==lst-1) posprv=i;
      if (poslst==lst && posprv==lst-1) continue;
      if (poslst!=1 || posprv!=2) {
        if (poslst!=3 || posprv!=2) {
          if (poslst+1!=posprv) {
            if (poslst!=1) {
              ans[m++]=poslst;
              reverse(a+1,a+poslst+1);
              for (i=1; i<=lst; i++) if (a[i]==lst-1) { posprv=i; break; }
            }
            ans[m++]=posprv-1;
            reverse(a+1,a+posprv);
          }
          ans[m++]=posprv+1;
          reverse(a+1,a+posprv+2);
        }
        ans[m++]=3;
        reverse(a+1,a+4);
      }
      ans[m++]=lst;
      reverse(a+1,a+lst+1);
    }
    printf("%d\n",m);
    for (i=0; i<m; i++) printf("%d%c",ans[i],(i==m-1)?'\n':' ');
  }
  return 0;
}