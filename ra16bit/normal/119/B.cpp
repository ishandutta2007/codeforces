#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,j,z,o,q,a[111];
bool u[111];
double x,y,cur;
vector <int> r;
int main() {
  scanf("%d%d",&n,&m); z=n/m; o=n%m;
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  scanf("%d",&q);
  x=10000;
  y=0;
  while (q--) {
    for (i=cur=0; i<z; i++) {
      scanf("%d",&j);
      cur+=a[j];
      u[j]=true;
    }
    cur/=double(z);
    x=min(x,cur);
    y=max(y,cur);
  }
  for (i=1; i<=n; i++) if (!u[i]) r.push_back(a[i]);
  sort(r.begin(),r.end());
  if (r.size()>=z+o) {
    for (cur=i=0; i<z; i++) cur+=r[i];
    cur/=double(z);
    x=min(x,cur);
    y=max(y,cur);
    for (cur=0, i=1; i<=z; i++) cur+=r[r.size()-i];
    cur/=double(z);
    x=min(x,cur);
    y=max(y,cur);
  }
  printf("%.8lf %.8lf\n",x,y);
  return 0;
}