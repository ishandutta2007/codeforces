#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,k,x,y,z;
long long r;
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&k);
  if (a>b) swap(a,b);
  if (a>c) swap(a,c);
  if (b>c) swap(b,c);
  x=min(a-1,k/3); k-=x; r=x+1;
  y=min(b-1,k/2); k-=y; r*=y+1;
  z=min(c-1,k); r*=z+1;
  printf("%I64d\n",r);
  return 0;
}