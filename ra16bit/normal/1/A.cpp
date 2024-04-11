#include <cstdio>
using namespace std;
int n,m,a;
long long x,y;
int main() {
  scanf("%d%d%d",&n,&m,&a);
  x=n/a; if (a*x<n) x++;
  y=m/a; if (a*y<m) y++;
  printf("%I64d\n",x*y);
  return 0;
}