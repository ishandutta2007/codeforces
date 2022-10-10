#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,m,r,b[31],k[31],p[31];
long long a[31],old[31][31],res=-1000000000000000000LL;
void rec(int l, bool can) {
  if (l==m) {
    long long cur=0;
    for (int i=0; i<n; i++) cur+=a[i]*k[i];
    res=max(res,cur);
    return;
  }
  for (int i=0; i<n; i++) old[l][i]=a[i];
  for (int i=0; i<n; i++) a[i]=old[l][p[i]]+r;
  rec(l+1,true);
  for (int i=0; i<n; i++) a[i]=old[l][i];
  if (can) {
    for (int i=0; i<n; i++) a[i]^=b[i];
    rec(l+1,false);
    for (int i=0; i<n; i++) a[i]^=b[i];
  }
  if ((m-l)%2==0) {
    long long cur=0;
    for (int i=0; i<n; i++) cur+=a[i]*k[i];
    res=max(res,cur);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&r);
  for (i=0; i<n; i++) scanf("%I64d",&a[i]);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  for (i=0; i<n; i++) scanf("%d",&k[i]);
  for (i=0; i<n; i++) { scanf("%d",&p[i]); p[i]--; }
  rec(0,true);
  printf("%I64d\n",res);
  return 0;
}