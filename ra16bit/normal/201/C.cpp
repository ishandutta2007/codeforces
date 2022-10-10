#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=100100;
int i,n,a[MX];
long long l[MX][2],r[MX][2],res;
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i]>1) l[i][1]=a[i]-(a[i]&1)+l[i-1][1];
    l[i][0]=max(l[i][1],a[i]-1+(a[i]&1)+l[i-1][0]);
  }
  for (i=n-2; i>=0; i--) {
    if (a[i+1]>1) r[i][1]=a[i+1]-(a[i+1]&1)+r[i+1][1];
    r[i][0]=max(r[i][1],a[i+1]-1+(a[i+1]&1)+r[i+1][0]);
  }
  for (i=0; i<n; i++) {
    res=max(res,l[i][0]+r[i][1]);
    res=max(res,l[i][1]+r[i][0]);
  }
  printf("%I64d\n",res);
  return 0;
}