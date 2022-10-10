#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,x,y,xx,yy,ax,ay,bx,by;
int count(int x, int y) {
  if (x<0) return -((-x)/y)-1;
  return x/y;
}
int main() {
  scanf("%d%d%d%d%d%d",&a,&b,&x,&y,&xx,&yy);
  //if (a==1 || b==1) a=b=2; else
  { a*=2; b*=2; }
  ax=count(x+y,a); bx=count(xx+yy,a);
  ay=count(x-y,b); by=count(xx-yy,b);
  printf("%d\n",max(abs(bx-ax),abs(by-ay)));
  return 0;
}