#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,z,r,a[8],c[8],x[200200];
bool w;
int main() {
  scanf("%d",&n);
  for (i=0; i<3; i++) {
    scanf("%d",&a[i]);
    z+=a[i];
  }
  sort(a,a+3);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
    if (x[i]>z) { puts("-1"); return 0; }
  }
  a[3]=a[0]+a[1];
  a[4]=a[0]+a[2];
  a[5]=a[1]+a[2];
  a[6]=z;
  if (a[3]<a[2]) { swap(a[2],a[3]); w=true; }
  for (i=0; i<n; i++) {
    for (j=0; j<7; j++) if (x[i]<=a[j]) break;
    c[j]++;
  }
  for (; c[6]>0; r++) c[6]--;
  for (; c[5]>0; r++) {
    c[5]--;
    if (c[0]>0) c[0]--;
  }
  for (; c[4]>0; r++) {
    c[4]--;
    for (j=1; j>=0; j--) if (c[j]>0) { c[j]--; break; }
  }
  if (w) {
    for (; c[0]>0; r++) {
      for (j=3; j>=0; j--) if (c[j]>0) { c[j]--; break; }
      for (j=1; j>=0; j--) if (c[j]>0) { c[j]--; break; }
      if (c[0]>0) c[0]--;
    }
    for (; c[0]>0 || c[1]>0 || c[2]>0 || c[3]>0; r++) {
      for (j=3; j>=0; j--) if (c[j]>0) { c[j]--; break; }
      for (j=2; j>=0; j--) if (c[j]>0) { c[j]--; break; }
    }
  } else {
    for (; c[3]>0; r++) {
      c[3]--;
      for (j=2; j>=0; j--) if (c[j]>0) { c[j]--; break; }
    }
    for (; c[0]>0 || c[1]>0; r++) {
      for (j=2; j>=0; j--) if (c[j]>0) { c[j]--; break; }
      for (j=1; j>=0; j--) if (c[j]>0) { c[j]--; break; }
      if (c[0]>0) c[0]--;
    }
    for (; c[2]>0; r++) c[2]-=2;
  }
  printf("%d\n",r);
  return 0;
}