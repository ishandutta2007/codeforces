#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,r,a[1010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=1; i<n; i++) if (a[i]==a[i-1] && a[i]>0) {
    if (i>1 && a[i-1]==a[i-2]) { puts("-1"); return 0; }
	r++;
  }
  printf("%d\n",r);
  return 0;
}