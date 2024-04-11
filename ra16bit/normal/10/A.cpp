#include <cstdio>
#include <algorithm>
using namespace std;
int n,p1,p2,p3,t1,t2,i,l,r,s,x,y;
int main() {
  scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
  for (i=0; i<n; i++) {
    scanf("%d%d",&l,&r);
    if (i>0) {
      y=min(x+t1,l); s+=(y-x)*p1; x=y;
      y=min(x+t2,l); s+=(y-x)*p2; x=y;
      s+=(l-x)*p3;
    }
    s+=(r-l)*p1; x=r;
  }
  printf("%d\n",s);
  return 0;
}