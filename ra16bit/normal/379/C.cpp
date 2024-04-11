#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,c,r[300100];
pair<int,int> a[300100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i].first);
    a[i].second=i;
  }
  sort(a,a+n);
  for (i=c=0; i<n; i++, c++) r[a[i].second]=c=max(c,a[i].first);
  for (i=0; i<n; i++) printf("%d%c",r[i],i==n-1?'\n':' ');
  return 0;
}