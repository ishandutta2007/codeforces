#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,r,best,a[55],b[55];
bool u[55];
void rec(int l) {
  if (l==n) {
    int cur=0;
    for (int i=0; i<l; i++) {
      int x=a[i];
      for (int j=i; j<l; j++) {
        x=min(x,a[j]);
        cur+=x;
      }
    }
    if (cur>best) { best=cur; r=0; }
    if (cur==best) if (++r==m) for (int i=0; i<n; i++) b[i]=a[i];
    return;
  }
  for (int i=1; i<=n; i++) if (!u[i]) {
    u[i]=true;
    a[l]=i;
    rec(l+1);
    u[i]=false;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  rec(0);
  for (int i=0; i<n; i++) printf("%d%c",b[i],(i==n-1)?'\n':' ');
  return 0;
}