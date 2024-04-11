#include <cstdio>
using namespace std;
int n,m,k,i,j,c,x[111000],y[111000],z[111000];
long long r;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<m; i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
  for (i=0; i<k; i++) {
    scanf("%d",&c);
    for (j=0; j<m; j++) if (x[j]<=c && y[j]>=c) r+=z[j]+c-x[j];
  }
  printf("%I64d\n",r);
  return 0;
}