#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[55];
long long m;
void rec(int x, int l, int r, long long m) {
  if (l==r) {
    a[l]=x;
    for (int i=0; i<n; i++) printf("%d%c",a[i],(i==n-1)?'\n':' ');
    return;
  }
  long long cur=1LL<<(r-l-1);
  if (m<=cur) {
    a[l]=x;
    rec(x+1,l+1,r,m);
  } else {
    a[r]=x;
    rec(x+1,l,r-1,m-cur);
  }
}
int main() {
  scanf("%d%I64d",&n,&m);
  rec(1,0,n-1,m);
  return 0;
}