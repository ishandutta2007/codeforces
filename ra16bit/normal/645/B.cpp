#include <cstdio>
#include <string>
using namespace std;
int n,m,i;
long long r;
int main() {
  scanf("%d%d",&n,&m);
  if (m>n/2) m=n/2;
  r=n-m-m+n-1; r*=m;
  printf("%I64d\n",r);
  return 0;
}