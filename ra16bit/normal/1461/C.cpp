#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,lst,a[100100];
double rst,p;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    for (lst=n; lst>=1; lst--) if (a[lst]!=lst) break;
    rst=int(lst>=1);
    while (m--) {
      scanf("%d%lf",&i,&p);
      if (i>=lst) rst*=1.0-p;
    }
    printf("%.11lf\n",1.0-rst);
  }
  return 0;
}