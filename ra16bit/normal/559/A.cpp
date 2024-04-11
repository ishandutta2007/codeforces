#include <cstdio>
#include <algorithm>
using namespace std;
int i,c,r,a[6];
int main() {
  for (i=0; i<6; i++) scanf("%d",&a[i]);
  c=a[0]*2+1;
  for (i=0; i<min(a[1],a[5]); i++, c+=2) r+=c;
  for (c--; i<max(a[1],a[5]); i++) r+=c;
  for (c--; i<a[1]+a[2]; i++, c-=2) r+=c;
  printf("%d\n",r);
  return 0;
}