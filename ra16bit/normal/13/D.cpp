#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,i,j,k,xx,yy,r,f[550][550],c[550];
pair <int, int> a[550];
double d,e,eps=1e-7;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  for (i=0; i<m; i++) {
    scanf("%d%d",&xx,&yy);
    for (j=0; j<n; j++) if (a[j].first==xx && yy<a[j].second) c[j]++;
    for (j=0; j<n; j++) for (k=j+1; k<n; k++) if (a[j].first<=xx && a[k].first>=xx) {
      e=double(a[k].second-a[j].second)/double(a[k].first-a[j].first);
      if (yy<=a[j].second+e*(xx-a[j].first)+eps) f[j][k]++;
    }
  }
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) for (k=j+1; k<n; k++) {
    xx=f[i][j]+f[j][k]-c[j]-f[i][k];
    if (xx==0) r++;
  }
  printf("%d\n",r);
  return 0;
}