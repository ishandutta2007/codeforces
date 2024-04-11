#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,n,ki,kj,k[1111],x[1111],y[1111];
long long t[1111];
double p[1111],f[1111],r;
bool cmp(int i, int j) { return t[i]<t[j]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%I64d%lf",&x[i],&y[i],&t[i],&p[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) {
    ki=k[i]; f[i]=p[ki];
    for (j=0; j<i; j++) {
      kj=k[j];
      if ((x[ki]-x[kj])*(x[ki]-x[kj])+(y[ki]-y[kj])*(y[ki]-y[kj])<=(t[ki]-t[kj])*(t[ki]-t[kj])) f[i]=max(f[i],f[j]+p[ki]);
    }
  }
  for (i=0; i<n; i++) if (f[i]>r) r=f[i];
  printf("%.10lf\n",r);
  return 0;
}