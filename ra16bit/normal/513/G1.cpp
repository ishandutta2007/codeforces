#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,rev,cnt,a[111];
void rec(int l) {
  if (l==m) {
    cnt++;
    for (int i=0; i<n; i++) for (int j=i; j<n; j++) if (a[i]>a[j]) rev++;
    return;
  }
  for (int i=0; i<n; i++) for (int j=i; j<n; j++) {
    for (int k=0; i+k<j-k; k++) swap(a[i+k],a[j-k]);
    rec(l+1);
    for (int k=0; i+k<j-k; k++) swap(a[i+k],a[j-k]);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  rec(0);
  printf("%.15lf\n",double(rev)/double(cnt));
  return 0;
}