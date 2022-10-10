#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,i,a[100100],b[100100];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  sort(a,a+n); reverse(a,a+n);
  sort(b,b+m); reverse(b,b+m);
  if (n>m) {
    puts("YES");
	return 0;
  }
  for (i=0; i<n; i++) if (a[i]>b[i]) {
    puts("YES");
	return 0;
  }
  puts("NO");
  return 0;
}