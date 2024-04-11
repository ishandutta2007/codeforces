#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,k,x,y,a[111];
bool solvefx(int prv, int lst) {
  int c=prv-a[i-2];
  int d=lst-prv;
  x+=int(c>=0)+int(d>=0);
  y+=int(c<=0)+int(d<=0);
  if (x>=j && y>=j) {
    a[i-1]=prv;
    a[i]=lst;
    return true;
  }
  x-=int(c>=0)+int(d>=0);
  y-=int(c<=0)+int(d<=0);
  return false;
}
bool solve() {
  if (solvefx(a[i-1],a[i])) return true;
  if (solvefx(-a[i-1],a[i])) return true;
  if (solvefx(a[i-1],-a[i])) return true;
  if (solvefx(-a[i-1],-a[i])) return true;
  return false;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    x=y=0;
    for (i=2, j=1; i<n; i+=2, j++) {
      if (solve()) continue;
      for (k=0; k<i; k++) a[k]=-a[k];
      swap(x,y);
      if (solve()) continue;
    }
    for (i=0; i<n; i++) printf("%d ",a[i]);
    puts("");
  }
  return 0;
}