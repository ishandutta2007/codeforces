#include <cstdio>
#include <algorithm>
using namespace std;
int n,l,r,x,y,i,a[100100];
long long cur,res,z,s;
int main() {
  scanf("%d%d%d%d%d",&n,&l,&r,&x,&y);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); s+=a[i]; }
  cur=s*r;
  res=s*r+(n-1LL)*y;
  for (i=0; i<n; i++) {
    cur+=(l-r)*a[i];
    if (i+1>n-i-1) z=max(0LL,i+i-n+1LL)*x; else z=max(0LL,n-i-i-3LL)*y;
    res=min(res,cur+z);
  }
  printf("%I64d\n",res);
  return 0;
}