#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,r,s,a[111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n); a[0]+=10;
  for (i=1; i<n; i++) a[i]+=a[i-1];
  for (i=0; i<n; i++) if (a[i]<=720) {
    r++;
    s+=max(0,a[i]-360);
  }
  printf("%d %d\n",r,s);
  return 0;
}