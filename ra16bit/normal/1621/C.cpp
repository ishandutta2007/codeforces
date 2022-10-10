#include <bits/stdc++.h>
using namespace std;
const int MX=10100;
int t,n,i,j,m,cur,a[MX],p[MX];
bool u[MX];
int ask(int x) {
  printf("? %d\n",x);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) u[i]=false;
    for (i=1; i<=n; i++) if (!u[i]) {
      a[m=0]=ask(i);
      while ((cur=ask(i))!=a[0]) a[++m]=cur;
      a[++m]=cur;
      for (j=0; j<m; j++) {
        u[a[j]]=true;
        p[a[j]]=a[j+1];
      }
    }
    putchar('!');
    for (i=1; i<=n; i++) printf(" %d",p[i]);
    putchar('\n');
    fflush(stdout);
  }
  return 0;
}