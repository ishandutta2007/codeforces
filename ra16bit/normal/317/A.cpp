#include <cstdio>
#include <algorithm>
using namespace std;
long long x,y,z,p,r;
int main() {
  scanf("%I64d%I64d%I64d",&x,&y,&z);
  if (x>=z || y>=z) { puts("0"); return 0; }
  if (x<=0 && y<=0) { puts("-1"); return 0; }
  if (x>y) swap(x,y);
  while (y<z) {
    p=(y-x+y)/y;
	r+=p;
	x+=y*p;
    swap(x,y);
  }
  printf("%I64d\n",r);
  return 0;
}