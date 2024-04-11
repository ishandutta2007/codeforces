#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,m,xa,ya,xb,yb,x,y;
long long l1,r1,l2,r2,c1,c2;
int ab(int x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d%d%d",&n,&m,&xa,&ya,&xb,&yb);
    x=ab(xa-xb); y=ab(ya-yb);
    l1=x; r1=n+1-x;
    if (l1>=r1) c1=(l1-r1+1)*m+(r1-1)*y+(n-l1)*y; else c1=l1*y+(n-r1+1)*y;
    l1=y; r1=m+1-y;
    if (l1>=r1) c2=(l1-r1+1)*n+(r1-1)*x+(m-l1)*x; else c2=l1*x+(m-r1+1)*x;
    printf("%I64d\n",max(c1,c2));
  }
  return 0;
}