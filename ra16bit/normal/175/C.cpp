#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j;
long long p[111],last,r;
pair <int, long long> a[111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%I64d%d",&a[i].second,&a[i].first);
  sort(a,a+n);
  scanf("%d",&m);
  for (i=1; i<=m; i++) {
    scanf("%I64d",&p[i]);
    p[i]-=last;
    last+=p[i];
    while (j<n) {
      if (a[j].second>=p[i]) {
        r+=p[i]*a[j].first*i;
        a[j].second-=p[i];
        p[i]=0;
        break;
      }
      r+=a[j].second*a[j].first*i;
      p[i]-=a[j++].second;
    }
  }
  for (; j<n; j++) r+=a[j].second*a[j].first*(m+1LL);
  printf("%I64d\n",r);
  return 0;
}