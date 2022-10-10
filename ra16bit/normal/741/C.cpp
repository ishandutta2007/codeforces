#include <cstdio>
using namespace std;
int n,i,j,k,a[200200],x[200200],y[200200],u[200200];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    a[x[i]]=y[i];
    a[y[i]]=x[i];
  }
  for (i=1; i<=2*n; i++) if (!u[i]) {
    for (j=i, k=0; !u[j]; k^=1) {
      u[j]=2-k;
      if (k) j=a[j]; else j=((j-1)^1)+1;
    }
  }
  for (i=0; i<n; i++) printf("%d %d\n",u[x[i]],u[y[i]]);
  return 0;
}