#include <stdio.h>
int x1,y1,x2,y2,n,m,a,b,r=3;
int main() {
  scanf("%d%d%d%d",&n,&m,&a,&b);
  x1=(--a)/m; y1=a%m;
  x2=(--b)/m; y2=b%m;
  if (x1==x2) r=1; else {
    if (y1==0) r--;
	if (y2==m-1 || y2==y1-1 || b==n-1) r--;
  }
  if (x2==x1+1 && r>2) r=2;
  printf("%d\n",r);
  return 0;
}