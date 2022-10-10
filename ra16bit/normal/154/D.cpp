#include <cstdio>
#include <algorithm>
using namespace std;
int l,r,a,b;
long long c,d;
bool q;
int main() {
  scanf("%d%d%d%d",&l,&r,&a,&b);
  d=r-l;
  if (d>=a && d<=b) {
    printf("FIRST\n%d\n",r);
    return 0;
  }
  if (d<0) {
    d=-d; a=-a; b=-b;
    swap(a,b); q=true;
  }
  if (a<=0) { puts("DRAW"); return 0; }
  c=d%(a+b);
  if (c>=a && c<=b) {
    if (q) c=-c;
    printf("FIRST\n%I64d\n",l+c);
  } else puts(c?"DRAW":"SECOND");
  return 0;
}