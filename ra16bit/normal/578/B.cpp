#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,x,y,z,i,j,a[200200],c[200200],d[200200];
long long cur,r;
int main() {
  scanf("%d%d%d",&n,&k,&x);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    c[i]=(c[i-1]|a[i]);
  }
  for (i=n; i>0; i--) d[i]=(d[i+1]|a[i]);
  for (i=1; i<=n; i++) {
    cur=a[i];
    for (j=0; j<k; j++) cur*=x;
    r=max(r,cur|c[i-1]|d[i+1]);
  }
  printf("%I64d\n",r);
  return 0;
}