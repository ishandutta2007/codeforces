#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,num,i,x,a[200200];
long long s,r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
    if (x>n-m) {
      a[num++]=i;
      s+=x;
    }
  }
  for (r=i=1; i<num; i++) r=(r*(a[i]-a[i-1]))%md;
  printf("%I64d %d\n",s,int(r));
  return 0;
}