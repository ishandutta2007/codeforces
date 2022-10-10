#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,sum,a[3030],s[3030],c[3030],p[3030],k[3030],x[3030],y[3030],z[3030];
int fs(int i) {
  if (p[i]!=i) p[i]=fs(p[i]);
  return p[i];
}
void un(int x, int y) {
  p[x]=y;
  c[y]+=c[x];
  s[y]+=s[x];
}
bool cmp(int i, int j) { return z[i]<z[j]; }
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    k[i]=i;
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    sum+=a[i];
    s[i]=a[i];
    c[i]=1;
    p[i]=i;
  }
  sort(k+1,k+n,cmp);
  for (i=1; i<n-1; i++) {
    un(fs(x[k[i]]),fs(y[k[i]]));
    for (j=1; j<=n; j++) if (fs(j)==j && sum-s[j]<c[j]) break;
    if (j<=n) break;
  }
  printf("%d\n",z[k[i]]);
  return 0;
}