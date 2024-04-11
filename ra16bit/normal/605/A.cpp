#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a,b[100100],c,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    b[a]=i;
  }
  r=c=1;
  for (i=2; i<=n; i++) if (b[i]<b[i-1]) {
    r=max(r,c);
    c=1;
  } else c++;
  r=max(r,c);
  printf("%d\n",n-r);
  return 0;
}