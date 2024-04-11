#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,x,y,z,a[555];
double r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    r=max(r,double(a[x]+a[y])/double(z));
  }
  printf("%.11lf\n",r);
  return 0;
}