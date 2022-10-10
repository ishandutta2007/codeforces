#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,sn,i,z,m,k[300010];
long long x[300010],y[300010],s,c1,c2;
bool cmp(int i, int j) {
  return (x[i]<x[j]);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n); s=c1=c2=0;
    for (i=0; i<2*n-1; i++) {
      scanf("%I64d%I64d",&x[i],&y[i]);
      s+=y[i]; k[i]=i;
    }
    sort(k,k+2*n-1,cmp);
    for (i=0; i<2*n-1; i++) if (i&1) c2+=y[k[i]]; else c1+=y[k[i]];
    puts("YES");
    if (c1*2>=s) for (i=0; i<2*n-1; i+=2) {
      if (i>0) printf(" ");
      printf("%d",k[i]+1);
    } else {
      for (i=1; i<2*n-1; i+=2) printf("%d ",k[i]+1);
      printf("%d",k[2*n-2]+1);
    }
    puts("");
  }
  return 0;
}