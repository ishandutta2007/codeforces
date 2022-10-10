#include <cstdio>
#include <algorithm>
using namespace std;
int n,i;
long long l,r,c,s,a[2222];
void rec(int l, long long s) {
  if (l>0) a[n++]=s;
  if (l<10) rec(l+1,s*10+4);
  if (l<10) rec(l+1,s*10+7);
}
int main() {
  rec(0,0);
  sort(a,a+n);
  scanf("%I64d%I64d",&l,&r);
  for (i=0; i<n; i++) if (l<=r && l<=a[i]) {
    c=min(r,a[i])-l+1;
    s+=c*a[i];
    l=a[i]+1;
  }
  printf("%I64d\n",s);
  return 0;
}