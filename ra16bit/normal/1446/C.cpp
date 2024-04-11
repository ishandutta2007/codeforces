#include <bits/stdc++.h>
using namespace std;
int n,i,a[200200];
int solve(int d, int l, int r) {
  if (d<0) return 0;
  if (((a[l]>>d)&1)==((a[r]>>d)&1)) return solve(d-1,l,r);
  int le=l,ri=r;
  while (le<ri) {
    int h=(le+ri)/2;
    if ((a[h]>>d)&1) ri=h; else le=h+1;
  }
  int vl=solve(d-1,l,ri-1);
  int vr=solve(d-1,ri,r);
  return min(vl+r-ri,vr+ri-1-l);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  printf("%d\n",solve(30,0,n-1));
  return 0;
}