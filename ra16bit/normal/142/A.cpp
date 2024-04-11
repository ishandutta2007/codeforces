#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i;
long long r,c=1000000000000000000LL;
void solve(int n, long long x) {
  for (int i=1; i*i<=n; i++) if (n%i==0) {
    r=max(r,(i+2LL)*(n/i+2LL)*x);
    c=min(c,(i+2LL)*(n/i+2LL)*x);
  }
}
int main() {
  scanf("%d",&n);
  for (i=1; i*i<=n; i++) if (n%i==0) {
    solve(i,n/i+1LL);
    if (i*i<n) solve(n/i,i+1LL);
  }
  printf("%I64d %I64d\n",c-n,r-n);
  return 0;
}