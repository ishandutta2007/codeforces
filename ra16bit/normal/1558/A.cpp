#include <bits/stdc++.h>
using namespace std;
int t,it,n,a,b,i,r,u[200200];
void check(int na, int nb, int i, int a, int b) {
  if (i>na) return;
  int cur=na-i;
  a-=i;
  b-=cur;
  if (b<0) return;
  u[cur+a]=it;
}
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d",&a,&b);
    n=a+b;
    for (i=0; i<=a; i++) {
      check(n-n/2,n/2,i,a,b);
      if (n&1) check(n/2,n-n/2,i,a,b);
    }
    for (r=i=0; i<=n; i++) if (u[i]==it) ++r;
    printf("%d\n",r);
    for (i=0; i<=n; i++) if (u[i]==it) printf("%d ",i);
    puts("");
  }
  return 0;
}