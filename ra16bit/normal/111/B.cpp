#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,c,r,x,y,n,a[100100];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x,&y);
    y=max(i-y,1); c=0;
    for (j=1; j*j<=x; j++) if (x%j==0) {
      if (a[j]<y) c++;
      a[j]=i;
      if (j<x/j) {
        if (a[x/j]<y) c++;
        a[x/j]=i;
      }
    }
    printf("%d\n",c);
  }
  return 0;
}