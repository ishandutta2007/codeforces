#include <cstdio>
#include <algorithm>
using namespace std;
int cur,res,mx,n,k,i,d[1010],c[1010],s[1010];
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&d[i]);
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  cur=mx=0;
  for (i=0; i<n; i++) {
    cur+=c[i];
    res+=d[i];
    mx=max(mx,c[i]);
    while (cur<d[i]) {
      cur+=mx;
      res+=k;
    }
    cur-=d[i];
  }
  printf("%d\n",res);
  return 0;
}