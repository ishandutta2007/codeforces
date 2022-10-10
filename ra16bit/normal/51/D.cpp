#include <stdio.h>
using namespace std;
int i,j,n,c,r,a[111111];
long long p,q;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) if (a[i]==0) {
    if (i<3) {
      for (j=1; j<n; j++) if (a[j]==0) r++;
      if (r==n-1) { puts("0"); return 0; }
      if (r==n-2) { puts("1"); return 0; }
    }
    for (j=r=0; j<n; j++) if (a[j]==0) { r++; c=j; } else if (j<n-1 && a[j+1]!=0) { p=a[j+1]; q=a[j]; }
    for (j=1; j<n; j++) if (a[j]!=0 && a[j-1]!=0 && a[j]*q!=p*a[j-1]) { puts("2"); return 0; }
    if (r==1 && (c==n-1 || c==0 || a[c-1]*p==a[c+1]*q)) puts("1"); else puts("2");
    return 0;
  }
  r=0; p=a[1]; q=a[0];
  for (i=2; i<n; i++) if (a[i]*a[0]!=a[i-1]*a[1]) {
    r++; c=i++;
  }
  if (r==0) { puts("0"); return 0; }
  if (r==1 && (c==n-1 || a[c-1]*p==a[c+1]*q)) { puts("1"); return 0; }
  for (r=0,i=3; i<n; i++) if (a[i]*a[1]!=a[i-1]*a[2]) r++;
  if (r==0) puts("1"); else puts("2");
  return 0;
}