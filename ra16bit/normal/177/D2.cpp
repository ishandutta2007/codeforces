#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,x,md,sum,a[100100],b[100100];
int main() {
  scanf("%d%d%d",&n,&m,&md);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=m; i++) {
    scanf("%d",&x);
    b[i]=(b[i-1]+x)%md;
  }
  for (i=1; i<=n; i++) {
    sum=(b[min(i,m)]-b[max(0,m-n+i-1)]+md)%md;
    printf("%d%c",(a[i]+sum)%md,i==n?'\n':' ');
  }
  return 0;
}