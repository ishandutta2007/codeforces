#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[111];
double b,c,x,y,z,r,p[111];
int main() {
  scanf("%d",&n);
  for (c=1, i=0; i<n; i++) {
    scanf("%d",&a[i]);
    p[i]=0.01*a[i];
    c*=p[i];
  }
  r=n;
  for (int it=0; 1-c>1e-10 && it<500000; it++) {
    r+=1-c;
    for (b=i=0; i<n; i++) {
      x=(1-p[i])*(0.01*a[i]);
      y=x/p[i];
      if (y>b) { b=y; z=x; j=i; }
    }
    c*=(1+b);
    p[j]+=z;
  }
  printf("%.8lf\n",r);
  return 0;
}