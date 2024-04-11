#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,l,r,s[200200],ans[200200];
pair<int,int> a[200200];
int sum(int x) {
  int r=0;
  for (; x>0; x&=x-1) r+=s[x];
  return r;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i].first);
    a[i].second=i;
  }
  sort(a,a+n);
  for (i=0; i<n; ) {
    for (j=i; j<n && a[i].first==a[j].first; j++) for (k=1; k<n; k++) {
      l=k*a[j].second;
      if (l+1>=n) break;
      r=min(l+k,n-1);
      ans[k]+=sum(r)-sum(l);
    }
    for (; i<j; i++) if (a[i].second>0)
      for (k=a[i].second; k<n; k=(k<<1)-(k&(k-1))) s[k]++;
  }
  for (i=1; i<n; i++) printf("%d ",ans[i]);
  return 0;
}