#include <bits/stdc++.h>
using namespace std;
const long long inf=22002002002002000;
long long x[77],y[77],z[77],ax,ay,bx,by,xs,ys,t,dst,cur;
int r,i,j,n;
long long aa(long long x) { return (x<0)?-x:x; }
int main() {
  cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>xs>>ys>>t;
  for (i=1; ; i++) {
    x[i]=ax*x[i-1]+bx;
    y[i]=ay*y[i-1]+by;
    z[i]=x[i]-x[i-1]+y[i]-y[i-1];
    if (x[i]>inf || y[i]>inf) break;
  }
  n=i;
  for (i=0; i<n; i++) {
    dst=aa(xs-x[i])+aa(ys-y[i]);
    if (dst>t) continue;
    for (cur=dst, j=i+1; j<n; j++) {
      cur+=z[j];
      if (cur>t) break;
    }
    r=max(r,j-i);
    for (cur=dst, j=i; j>0; j--) {
      cur+=z[j];
      if (cur>t) break;
    }
    r=max(r,i-j+1);
  }
  cout<<r;
  return 0;
}