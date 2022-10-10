#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,i,j;
pair <int, int> a[3333];
long long s[3333][3333],f[3333][2],inf=1000000000LL;
int main() {
  scanf("%d",&n); inf*=inf;
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) s[i][j]=s[i][j-1]+a[j].first-a[i].first;
  f[0][0]=f[0][1]=a[0].second;
  for (i=1; i<n; i++) {
    f[i][0]=f[i][1]=f[i-1][1]+a[i].second;
    for (j=i-1; j>=0; j--) f[i][1]=min(f[i][1],f[j][0]+s[j][i]);
  }
  printf("%I64d\n",f[n-1][1]);
  return 0;
}