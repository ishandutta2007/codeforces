#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[100100],r[100100];
long long s[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=m; i++) {
    scanf("%d",&a[i]);
    if (a[i]+i-1>n) { puts("-1"); return 0; }
    s[i]=s[i-1]+a[i];
  }
  if (s[m]<n) { puts("-1"); return 0; }
  r[m]=n-a[m]+1;
  for (i=m-1; i>0; i--) r[i]=min(min(s[i-1]+1,r[i+1]-1LL),n-a[i]+1LL);
  for (i=1; i<=m; i++) printf("%d ",r[i]);
  return 0;
}