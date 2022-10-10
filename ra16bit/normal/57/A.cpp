#include <cstdio>
#include <algorithm>
using namespace std;
int n,xa,ya,xb,yb;
int main() {
  scanf("%d%d%d%d%d",&n,&xa,&ya,&xb,&yb);
  if (xa==n) { xa=0; xb=n-xb; }
  if (ya==n) { ya=0; yb=n-yb; }
  if (ya!=0) { swap(xa,ya); swap(xb,yb); }
  if (yb==0) printf("%d\n",abs(xb-xa)); else
    if (yb==n) printf("%d\n",min(xa+xb,n-xa+n-xb)+n); else
      if (xb==0) printf("%d\n",yb+xa); else printf("%d\n",yb+n-xa);
  return 0;
}