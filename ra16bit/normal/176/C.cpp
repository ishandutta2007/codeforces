#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,x,y,a,b;
int main() {
  scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
  n=abs(x-a);
  m=abs(y-b);
  if (n>m) swap(n,m);
  puts((m<4 || (n<3 && m<5))?"First":"Second");
  return 0;
}