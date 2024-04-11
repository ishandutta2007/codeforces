#include <cstdio>
using namespace std;
int n,d,i,b;
long long r,c,a[2010];
int main() {
  scanf("%d%d",&n,&d);
  for (i=0; i<n; i++) {
    scanf("%d",&b); a[i]=b;
    if (i>0 && a[i]<=a[i-1]) {
      c=(a[i-1]-a[i]+d)/d;
      r+=c; a[i]+=c*d;
    }
  }
  printf("%I64d\n",r);
  return 0;
}