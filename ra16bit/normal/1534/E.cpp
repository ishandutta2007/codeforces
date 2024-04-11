#include <bits/stdc++.h>
using namespace std;
int n,m,d,cur,i,j,p,r,x,a[505],k[505];
bool cmp(int x, int y) { return a[x]>a[y]; }
int main() {
  scanf("%d%d",&n,&m);
  for (d=1; d<=500; d++) if (d*m>=n && (d*m)%2==n%2) {
    cur=(d*m)/n;
    if (cur%2==0) --cur;
    x=d*m-cur*n;
    if (x%2==0 && 2*n>=x) {
      for (j=0; j<n; j++) {
        a[j]=cur;
        if (x>0) {
          a[j]+=2;
          x-=2;
        }
      }
      if (a[0]<=d) break;
    }
  }
  if (d>500) {
    puts("-1");
    fflush(stdout);
    return 0;
  }
  for (i=0; i<n; i++) k[i]=i;
  while (true) {
    sort(k,k+n,cmp);
    putchar('?');
    for (j=0; j<m; j++) if (a[k[j]]>0) {
      printf(" %d",k[j]+1);
      --a[k[j]];
    }
    putchar('\n');
    fflush(stdout);
    scanf("%d",&x);
    r^=x;
    for (j=0; j<n; j++) if (a[j]>0) break;
    if (j>=n) break;
  }
  printf("! %d\n",r);
  fflush(stdout);
  return 0;
}