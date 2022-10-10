#include <cstdio>
#include <algorithm>
using namespace std;
int i,k,n,a[100100];
pair <int, int> c[100100];
long long b,s;
bool u[100100];
int main() {
  scanf("%d%d",&n,&k);
  scanf("%I64d",&b);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    c[i].first=a[i];
    c[i].second=i;
  }
  sort(c,c+n-1);
  reverse(c,c+n-1);
  for (i=0; i<k; i++) {
    s+=c[i].first;
    u[c[i].second]=true;
  }
  if (b>=s) {
    printf("%d\n",n);
    return 0;
  }
  for (i=0; i<n; i++) if (u[i] || b<s-c[k-1].first+a[i]) {
    printf("%d\n",i+1);
    break;
  }
  return 0;
}