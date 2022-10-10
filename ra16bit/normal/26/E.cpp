#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,p,z,s,a[111],k[111];
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); k[i-1]=i; }
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) {
    s+=a[k[i]];
    if (s>=m) break;
  }
  if (i==n) { puts("No"); return 0; }
  if (s==m) {
    puts("Yes"); p=i;
    for (i=p; i<n; i++) {
      if (i>p) putchar(' ');
      printf("%d",k[i]);
    }
    for (i=n-1; i>=p; i--) for (j=1; j<2*a[k[i]]; j++) printf(" %d",k[i]);
    for (i=p-1; i>=0; i--) for (j=0; j<2*a[k[i]]; j++) printf(" %d",k[i]);
    puts("");
    return 0;
  } else if (i==0) {
    if (m<2 || n<2) puts("No"); else {
      puts("Yes");
      for (i=0; i<n; i++) {
        if (i>0) putchar(' ');
        printf("%d",k[i]);
      }
      z=a[k[0]]-m+1;
      for (i=1; i<2*z; i++) printf(" %d",k[0]);
      for (i=2; i<n; i++) for (j=1; j<2*a[k[i]]; j++) printf(" %d",k[i]);
      printf(" %d",k[1]);
      printf(" %d",k[0]);
      for (j=2; j<2*a[k[1]]; j++) printf(" %d",k[1]);
      for (j=2*z+1; j<2*a[k[0]]; j++) printf(" %d",k[0]);
      puts("");
    }
    return 0;
  }
  puts("Yes"); p=i;
  for (i=p-1; i<n; i++) {
    if (i>=p) putchar(' ');
    printf("%d",k[i]);
  }
  z=s-m;
  for (i=1; i<2*z; i++) printf(" %d",k[p]);
  for (i=p+1; i<n; i++) for (j=1; j<2*a[k[i]]; j++) printf(" %d",k[i]);
  printf(" %d",k[p-1]);
  for (j=2*z; j<2*a[k[p]]; j++) printf(" %d",k[p]);
  for (j=2; j<2*a[k[p-1]]; j++) printf(" %d",k[p-1]);
  for (i=0; i<p-1; i++) for (j=0; j<2*a[k[i]]; j++) printf(" %d",k[i]);
  puts(""); return 0;
}