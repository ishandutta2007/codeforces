#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,x;
long long cur,cx,cy;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    if (i==0 || cur-x>cx) cx=cur-x;
    if (i==0 || cur+x>cy) cy=cur+x;
    cur=max(cur,cx+x);
    cur=max(cur,cy-x);
  }
  printf("%I64d\n",cur);
  return 0;
}